#include "stdafx.h"

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

void getEvent(char *com) {
	char m = com[0];
	char check;
	static int count = 0;
	static bool tell_switch = true;
	OldX = playerPosX;
	OldY = playerPosY;

	switch (m)
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
		switch (m)
		{
		case 'w':
			printf("플레이어가 위쪽으로 이동합니다.\n");
			break;
		case 's':
			printf("플레이어가 아래쪽으로 이동합니다.\n");
			break;
		case 'a':
			printf("플레이어가 왼쪽으로 이동합니다.\n");
			break;
		case 'd':
			printf("플레이어가 오른쪽으로 이동합니다.\n");
			break;
		default:
			break;
		}
		cTilteMap1[OldX + OldY * 8] = 0;
		break;
	case 1:
		printf("막힌길 입니다.\n");
		playerPosX = OldX;
		playerPosY = OldY;
		break;
	case 2:
		cTilteMap1[OldX + OldY * 8] = 0;
		system("cls");
		printMap();
		printf("탈출 성공~~!!! 수고하셨습니다.\n");

		return;
	case 3:
		if (tell_switch) {
			printf("전화가 울리고있습니다. 받으시겠습니까?(y/n)");
			scanf_s("%c", &check, sizeof(check));
			getchar();

			if (check == 'y') {
				printf("전화는 바로 끊어지고 무언가 떨어지는 소리가 났다.\n");
				switch (m)
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
					printf("전화가 끊어졌다\n그 이후로는 아무일도 일어나지 않아 시간만이 지나갔다.\n");
					printf("GAME OVER\n");
					return;
				}

			}
		}
		else {
			printf("전화기가 놓여있다.\n");
		}

		playerPosX = OldX;
		playerPosY = OldY;
		break;
	case 4:
		printf("스위치가 놓여있습니다. 누르시겠습니까? (y,n)");
		scanf_s("%c", &check, sizeof(check));
		getchar();

		if (check == 'y') {
			printf("무거운 무언가가 움직이는 소리가 들렸다.\n");
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
}

int main() {
	char szCmd[32];
	//bool switch_switch = true;
	playerPosX = 2;
	playerPosY = 5;
	

	while ((playerPosX + playerPosY * 8 != 55) && (playerPosX + playerPosY * 8 != 18)) {
		system("cls");

		cTilteMap1[playerPosX + playerPosY * 8] = 9;
		printMap();
		printf("커멘드를 입력하세요(help) : ");
		scanf_s("%s", szCmd, sizeof(szCmd));
		getchar();

		if (!strcmp(szCmd, "quit")) {
			printf("프로그램을 종료 합니다.\n");
			break;
		}
		else if (!strcmp(szCmd, "w")) {
			getEvent(szCmd);
		}
		else if (!strcmp(szCmd, "a")) {
			getEvent(szCmd);
		}
		else if (!strcmp(szCmd, "s")) {
			getEvent(szCmd);
		}
		else if (!strcmp(szCmd, "d")) {
			getEvent(szCmd);
		}
		/*else if (!strcmp(szCmd, "move")) {
			while (true) {
				system("cls");

				cTilteMap1[playerPosX + playerPosY * 8] = 9;

				printMap();

				char m, check;
				int x, y;
				x = playerPosX;
				y = playerPosY;

				printf("방향을 입력하세요(w-위,a-왼쪽,s-아래,d-오른쪽,c-커멘드로이동) : ");
				scanf_s("%c", &m, sizeof(m));
				getchar();

				if (m == 'c') break;

				switch (m)
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
					switch (m)
					{
					case 'w':
						printf("플레이어가 위쪽으로 이동합니다.\n");
						break;
					case 's':
						printf("플레이어가 아래쪽으로 이동합니다.\n");
						break;
					case 'a':
						printf("플레이어가 왼쪽으로 이동합니다.\n");
						break;
					case 'd':
						printf("플레이어가 오른쪽으로 이동합니다.\n");
						break;
					default:
						break;
					}
					cTilteMap1[x + y * 8] = 0;
					break;
				case 1:
					printf("막힌길 입니다.\n");
					playerPosX = x;
					playerPosY = y;
					break;
				case 2:
					cTilteMap1[x + y * 8] = 0;
					system("cls");
					printMap();
					printf("탈출 성공~~!!! 수고하셨습니다.\n");
					return 0;
				case 3:
					if (tell_switch) {
						printf("전화가 울리고있습니다. 받으시겠습니까?(y/n)");
						scanf_s("%c", &check, sizeof(check));
						getchar();

						if (check == 'y') {
							printf("전화는 바로 끊어지고 무언가 떨어지는 소리가 났다.\n");
							switch (m)
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
								printf("전화가 끊어졌다\n그 이후로는 아무일도 일어나지 않아 시간만이 지나갔다.\n");
								printf("GAME OVER\n");
								return 0;
							}

						}
					}
					else {
						printf("전화기가 놓여있다.\n");
					}

					playerPosX = x;
					playerPosY = y;
					break;
				case 4:
					printf("스위치가 놓여있습니다. 누르시겠습니까? (y,n)");
					scanf_s("%c", &check, sizeof(check));
					getchar();

					if (check == 'y') {
						printf("무거운 무언가가 움직이는 소리가 들렸다.\n");
						cTilteMap1[55] = 2;
						cTilteMap1[x + y * 8] = 0;
					}
					else {
						playerPosX = x;
						playerPosY = y;
					}
					break;
				default:
					break;
				}
				system("pause");
			}
		}*/
		else if (!strcmp(szCmd, "help")) {
			printf("--커맨드 목록--\n");
			printf("quit : 종료\n");
			printf("w : 위로 이동\n");
			printf("a : 왼쪽으로 이동\n");
			printf("s : 아래로 이동\n");
			printf("d : 오른쪽으로 이동\n");
		}
			
		/*else if (!strcmp(szCmd, "dump")) {
			
		}*/
		else {
			printf_s("입력 하신 커멘드는 : %s 입니다.\n", szCmd);
		}
		system("pause");
	}

	return 0;
}