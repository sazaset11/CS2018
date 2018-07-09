#include "stdafx.h"

using namespace tge;

int cTilteMap1[64] = {
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 3, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1
};
int playerPosX, playerPosY, OldX, OldY;
bool gameover = false;

void printMap() {
	cTilteMap1[playerPosX + playerPosY * 8] = 9;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			//printf("%2c", cTilteMap1[x + y * 8]);
			switch (cTilteMap1[x + y * 8])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("■");
				break;
			case 2:
				printf("□");
				break;
			case 3:
				printf("☎");
				break;
			case 4:
				printf("⊙");
				break;
			case 9:
				printf("Ø");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}

int getEvent(char com) {
	int num = 0;
	char check;
	static int count = 0;
	static bool tell_switch = true;
	OldX = playerPosX;
	OldY = playerPosY;

	switch (com)
	{
	case 'w':
		playerPosY--;
		break;
	case 's':
		playerPosY++;
		break;
	case 'a':
		playerPosX--;
		break;
	case 'd':
		playerPosX++;
		break;
	default:
		break;
	}

	switch (cTilteMap1[playerPosX + playerPosY * 8])
	{
	case 0:
		switch (com)
		{
		case 'w':
			num = 1;
			break;
		case 's':
			num = 2;
			break;
		case 'a':
			num = 3;
			break;
		case 'd':
			num = 4;
			break;
		default:
			break;
		}
		cTilteMap1[OldX + OldY * 8] = 0;
		break;
	case 1:
		num = 5;
		playerPosX = OldX;
		playerPosY = OldY;
		break;
	case 2:
		cTilteMap1[OldX + OldY * 8] = 0;
		system("cls");
		printMap();
		num = 6;
		return num;
	case 3:
		if (tell_switch) {
			printf("전화가 울리고있습니다. 받으시겠습니까?(y/n)");
			scanf_s("%c", &check, sizeof(check));
			getchar();

			if (check == 'y') {
				num = 7;
				switch (com)
				{
				case 'w':
					cTilteMap1[10] = 4;
					break;
				case 's':
					cTilteMap1[26] = 4;
					break;
				case 'a':
					cTilteMap1[17] = 4;
					break;
				case 'd':
					cTilteMap1[19] = 4;
					break;
				default:
					break;
				}
				tell_switch = false;
			}
			else {
				count++;

				if (count > 3) {
					num = 8;
					playerPosX = OldX;
					playerPosY = OldY;
					return num;
				}

			}
		}
		else {
			num = 9;
		}
		playerPosX = OldX;
		playerPosY = OldY;
		break;
	case 4:
		printf("스위치가 놓여있습니다. 누르시겠습니까? (y,n)");
		scanf_s("%c", &check, sizeof(check));
		getchar();

		if (check == 'y') {
			num = 10;
			cTilteMap1[55] = 2;
			cTilteMap1[OldX + OldY * 8] = 0;
		}
		else {
			playerPosX = OldX;
			playerPosY = OldY;
		}
		break;
	default:
		break;
	}
	return num;
}

void printMessage(int num) {
	switch (num)
	{
	case 1:
		printf("플레이어가 위쪽으로 이동했습니다.\n");

		break;
	case 2:
		printf("플레이어가 아래쪽으로 이동했습니다.\n");

		break;
	case 3:
		printf("플레이어가 왼쪽으로 이동했습니다.\n");

		break;
	case 4:
		printf("플레이어가 오른쪽으로 이동했습니다.\n");

		break;
	case 5:
		printf("막힌길 입니다.\n");

		break;
	case 6:
		printf("탈출 성공~~!!! 수고하셨습니다.\n");

		break;
	case 7:
		printf("전화는 바로 끊어지고 무언가 떨어지는 소리가 났다.\n");

		break;
	case 8:
		printf("전화가 끊어졌다\n그 이후로는 아무일도 일어나지 않아 시간만이 지나갔다.\n");
		printf("GAME OVER\n");
		gameover = true;

		break;
	case 9:
		printf("전화기가 놓여있다.\n");

		break;
	case 10:
		printf("무거운 무언가가 움직이는 소리가 들렸다.\n");

		break;
	default:
		break;
	}
}

int main() {
	HANDLE hdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD fdwSaveOldMode, cNumRead, fdwMode;
	INPUT_RECORD irlnBuf[128];

	GetConsoleMode(hdin, &fdwSaveOldMode); // 기본 콘솔모드를 저장
										   // 마우스모드 설정
	fdwMode = ENABLE_EXTENDED_FLAGS;
	SetConsoleMode(hdin, fdwMode); // 에디터모드 비활성화
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; // 마우스모드 활성화
	SetConsoleMode(hdin, fdwMode);
	char szCmd[32];
	//bool switch_switch = true;
	playerPosX = 2;
	playerPosY = 5;
	int num;


	while ((playerPosX + playerPosY * 8 != 55) && (playerPosX + playerPosY * 8 != 18)) {
		ReadConsoleInput(hdin, irlnBuf, sizeof(irlnBuf) / sizeof(INPUT_RECORD), &cNumRead);
		for (int i = 0; i < cNumRead; i++) {
			
			//setCursor(hdout, 19, 8);
			//scanf_s("%s", szCmd, sizeof(szCmd));
			//getchar();
			if (irlnBuf[i].EventType == KEY_EVENT)
			{
				if (irlnBuf->Event.KeyEvent.bKeyDown) {
					//printf("key pressed %d\n", irlnBuf[i].Event.KeyEvent.wVirtualKeyCode);
				}
				else {
					switch (irlnBuf[i].Event.KeyEvent.wVirtualKeyCode)
					{
					case 37:
						num = getEvent('a');
						break;
					case 38:
						num = getEvent('w');
						break;
					case 39:
						num = getEvent('d');
						break;
					case 40:
						num = getEvent('s');
						break;
					default:
						break;
					}
					if (irlnBuf[i].Event.KeyEvent.wVirtualKeyCode == 81) return 0;

					//printf("key released %d\n", irlnBuf[i].Event.KeyEvent.wVirtualKeyCode);
				}
			}
			system("cls");
			setCursor(hdout, 0, 0);
			cTilteMap1[playerPosX + playerPosY * 8] = 9;
			printMap();
			setCursor(hdout, 0, 8);
			printf("커멘드를 입력하세요.\n");
			printMessage(num);
			if (gameover) return 0;

				//if (!strcmp(szCmd, "quit")) {
				//	printf("프로그램을 종료 합니다.\n");
				//	break;
				//}
				//else if (!strcmp(szCmd, "w")) {
				//	getEvent(szCmd);
				//}
				//else if (!strcmp(szCmd, "a")) {
				//	getEvent(szCmd);
				//}
				//else if (!strcmp(szCmd, "s")) {
				//	getEvent(szCmd);
				//}
				//else if (!strcmp(szCmd, "d")) {
				//	getEvent(szCmd);
				//}
				//else if (!strcmp(szCmd, "help")) {
				//	printf("--커맨드 목록--\n");
				//	printf("quit : 종료\n");
				//	printf("w : 위로 이동\n");
				//	printf("a : 왼쪽으로 이동\n");
				//	printf("s : 아래로 이동\n");
				//	printf("d : 오른쪽으로 이동\n");
				//}

				///*else if (!strcmp(szCmd, "dump")) {

				//}*/
				//else {
				//	printf_s("입력 하신 커멘드는 : %s 입니다.\n", szCmd);
				//}
				//system("pause");
			}
		}
		SetConsoleMode(hdin, fdwSaveOldMode);

		return 0;
	}