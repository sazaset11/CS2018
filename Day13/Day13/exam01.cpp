#include "stdafx.h"
#include "../../engine/TGE.h"
#include "PlayerObject.h"

//////주인공 오브젝트////////////
//COORD g_cdPlayer.m_Position;
//int g_cdPlayer.m_nKeyCount;
////////////////////////////////
playerobject::S_PlayerObject g_cdPlayer;
int main() {
	HANDLE hdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD fdwOldMode;
	CHAR_INFO *pBackScreenBuffer = tge::CreateScreenBuffer();
	CHAR_INFO *pMapDataBuffer = tge::CreateScreenBuffer();
	bool _bLoop = true;
	static int _nFsm = 0;

	GetConsoleMode(hdin, &fdwOldMode);
	SetConsoleMode(hdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	tge::loadBinary(pMapDataBuffer, "../../res/map1");
	playerobject::Init(&g_cdPlayer, 15, 5);
	//46, 1(마지막 문 앞)

	while (_bLoop) {
		static char szCmdBuf[128];

		//tge::updateBuffer(hdout);
		tge::setCursor(hdout, 0, 0);
		tge::setCursor(hdout, 0, 25);
		//입력 처리
		switch (_nFsm) {
		case 0://비동기 모드
			static DWORD cNumRead;
			static INPUT_RECORD irInputBuf[128];

			printf("							");
			tge::setCursor(hdout, 0, 26);
			ReadConsoleInput(hdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0; i < cNumRead; i++) {
				if (irInputBuf[i].EventType == KEY_EVENT) {
					if (irInputBuf[i].Event.KeyEvent.bKeyDown) {
						//printf("%d", irInputBuf[i].Event.KeyEvent.wVirtualKeyCode);
						//printf("%d %d %d", fdwOldMode, i, cNumRead);
						switch (irInputBuf[i].Event.KeyEvent.wVirtualKeyCode) {
						case 13: //커멘드 입력 모드 전환 
							SetConsoleMode(hdin, fdwOldMode);
							_nFsm = 1;
							break;
						case VK_UP:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 0 -1");
							break;
						case VK_DOWN:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 0 1");
							break;
						case VK_LEFT:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move -1 0");
							break;
						case VK_RIGHT:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 1 0");
							break;
						default:
							break;
						}
					}
				}
			}
			break;
		case 1://동기 모드
			printf("						]");
			tge::setCursor(hdout, 0, 25);
			printf("[cmd > ");
			gets_s(szCmdBuf, sizeof(szCmdBuf));

			SetConsoleMode(hdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
			_nFsm = 0;
			break;
		default:
			break;
		}
		//커멘드 처리
		{
			char szTokenBuf[8][MAX_TOKEN_SIZE];

			if (tge::doTokenize(szCmdBuf, szTokenBuf) > 0) {
				if (!strcmp(szTokenBuf[0], "quit")) {
					_bLoop = false;
				}
				else if (!strcmp(szTokenBuf[0], "move")) {
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					playerobject::move(&g_cdPlayer, pMapDataBuffer, _dx, _dy);
				}
				else if (!strcmp(szTokenBuf[0], "use")) {
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					if (!playerobject::use(&g_cdPlayer, pMapDataBuffer, _dx, _dy)) _bLoop = false;
				}
				else if (!strcmp(szTokenBuf[0], "get")) {
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					playerobject::get(&g_cdPlayer, pMapDataBuffer, _dx, _dy);
				}
				else if (!strcmp(szTokenBuf[0], "drop")) {

				}
				else if (!strcmp(szTokenBuf[0], "teleport")) {
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					g_cdPlayer.m_Position.X = _dx;
					g_cdPlayer.m_Position.Y = _dy;
				}
			}

			szCmdBuf[0] = NULL;
		}
		//배경 다시 그리기
		memcpy_s(pBackScreenBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pMapDataBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));
		//오브잭트 그리기
		playerobject::DrawObject(&g_cdPlayer, pBackScreenBuffer);
		//전체 화면 갱신
		memcpy_s(tge::g_chiBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pBackScreenBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));
		tge::updateBuffer(hdout, tge::g_chiBuffer);
	}

	free(pBackScreenBuffer);
	free(pMapDataBuffer);

	return 0;
}