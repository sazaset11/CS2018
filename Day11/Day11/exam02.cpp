#include "stdafx.h"
using namespace tge;

int main() {
	HANDLE hdout = GetStdHandle(STD_OUTPUT_HANDLE);
	static char szCmdBuf[32];
	static char szTokenBuf[8][16];

	clearScreenBuffer(0x2e, 0x0007);
	updateBuffer(hdout);

	while (1) {
		setCursor(hdout, 0, 25);

		printf("					]");

		setCursor(hdout, 0, 25);

		printf("[cmd > ");
		gets_s(szCmdBuf, sizeof(szCmdBuf));

		doTokenize(szCmdBuf, szTokenBuf);

		if (!strcmp(szTokenBuf[0], "quit")) {
			break;
		}
		else if (!strcmp(szTokenBuf[0], "set")) {
			int _xpos = atoi(szTokenBuf[1]);
			int _ypos = atoi(szTokenBuf[2]);
			int _code = strtol(szTokenBuf[3], NULL, 16);
			int _attr = strtol(szTokenBuf[4], NULL, 16);
			setCharacter(_xpos, _ypos, _code, _attr);
		}
		else if (!strcmp(szTokenBuf[0], "clear")) {
			clearScreenBuffer(0x2e, 0x0007);
		}
		else if (!strcmp(szTokenBuf[0], "save")) {
			FILE *fp;
			fopen_s(&fp, szTokenBuf[1], "w+");
			for (int i = 0; i < 2000; i++) {
				fprintf(fp, "%d %d %d\n", g_chiBuffer[i].Char, g_chiBuffer[i].Attributes, i);
			}
			fclose(fp);
		}
		else if (!strcmp(szTokenBuf[0], "load")) {
			FILE *fp;
			char loadBuf[16];
			char *temp = NULL;
			char *token;
			const char *pzDelimiter = " ";

			fopen_s(&fp, szTokenBuf[1], "r");

			if (fp) {
				int i = 0;
				//for (int i = 0; i < 2000; i++) {
				//	fgets(loadBuf, 16, fp);
				//	//printf("%s", loadBuf);
				//	token = strtok_s(loadBuf, pzDelimiter, &temp);
				//	int _code = atoi(token);
				//	token = strtok_s(NULL, pzDelimiter, &temp);
				//	int _attr = atoi(token);
				//	setCharacter(i, 0, _code, _attr);
				//}
				while (fgets(loadBuf, sizeof(loadBuf), fp) != NULL) {
					doTokenize(loadBuf, szTokenBuf);
					WCHAR _code = atoi(szTokenBuf[0]);
					WORD _attr = atoi(szTokenBuf[1]);
					setCharacter(i++, 0, _code, _attr);
				}
				fclose(fp);
			}
			else {
				printf("세이브파일이 존재하지 않습니다.\n");
			}
		}

		updateBuffer(hdout);
	}

	return 0;
}