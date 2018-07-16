#include "stdafx.h"
#include "TGE.h"
#include "PlayerObject.h"


//주인공 오브젝트
//COORD g_cdPlayerPos;

int main() {
	HANDLE hdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD fdwOldMode;
	playerobject::S_PlayerObject g_player;
	playerobject::Init(&g_player, 15, 5);

	GetConsoleMode(hdin, &fdwOldMode);
	SetConsoleMode(hdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	//TGE::loadBinary(TGE::g_chiBuffer, "../../res/map1");
	TGE::clearScreenBuffer(0x20, 0x0090);
	

	bool _bLoop = true;
	static int _nFsm = 0;

	while (_bLoop) {
		TGE::updateBuffer(hdout, TGE::g_chiBuffer);
		TGE::setCursor(hdout, 0, 0);
		TGE::setCursor(hdout, 0, 25);
		static char szCmdBuf[128];
		//입력 처리
		switch (_nFsm) {
		case 0://비동기 모드
			static DWORD cNumRead;
			static INPUT_RECORD irInputBuf[128];

			printf("							");
			TGE::setCursor(hdout, 0, 26);
			ReadConsoleInput(hdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0; i < cNumRead; i++) {
				if (irInputBuf[i].EventType == KEY_EVENT) {
					if (irInputBuf[i].Event.KeyEvent.bKeyDown) {
						printf("%d", irInputBuf[i].Event.KeyEvent.wVirtualScanCode);

						switch (irInputBuf[i].Event.KeyEvent.wVirtualScanCode) {
						case 28: //커멘드 입력 모드 전환 
							SetConsoleMode(hdin, fdwOldMode);
							_nFsm = 1;

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
			TGE::setCursor(hdout, 0, 25);
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

			if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0) {

				if (!strcmp(szTokenBuf[0], "quit")) {
					_bLoop = false;
				}
				else if (!strcmp(szTokenBuf[0], "move")) {
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					g_player.m_Position.X += _dx;
					g_player.m_Position.Y += _dy;
				}
			}
			szCmdBuf[0] = NULL;
		}
		//오브잭트 처리
		TGE::setCharacter(TGE::g_chiBuffer, g_player.m_Position.X, g_player.m_Position.Y, 0x41, 0x000f);
	}

	return 0;
}