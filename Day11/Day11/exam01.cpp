#include "stdafx.h"
using namespace tge;

int main() {
	HANDLE hdout = GetStdHandle(STD_OUTPUT_HANDLE);
	clearScreenBuffer(0x2e, 0x0007);
	updateBuffer(hdout);
	static char szBuf[32];
	static char szBufToken[8][16];

	while (1) {

		setCursor(hdout, 0, 25);

		printf("																																											");

		setCursor(hdout, 0, 25);

		printf("명령어 > ");
		gets_s(szBuf, sizeof(szBuf));

		doTokenize(szBuf, szBufToken);
		/*szpTemp = strtok_s(szBuf, pzDelimiter, &pNextToken);

		while (szpTemp) {
			strcpy_s(szBufToken[_nTokenIndex++], sizeof(szBufToken[_nTokenIndex]), szpTemp);
			szpTemp = strtok_s(NULL, pzDelimiter, &pNextToken);
		}

		printf("토큰 수 : %d\n", _nTokenIndex);

		for (int i = 0; i < _nTokenIndex; i++) {
			printf("%s\n", szBufToken[i]);
		}*/

		if (!strcmp(szBufToken[0], "quit")) {
			printf("bye~\n");
			break;
		}
		else if (!strcmp(szBufToken[0], "setchar")) {
			int _xpos = atoi(szBufToken[1]);
			int _ypos = atoi(szBufToken[2]);
			int _code = strtol(szBufToken[3], NULL, 16);
			int _attr = strtol(szBufToken[4], NULL, 16);
			setCharacter(_xpos, _ypos, _code, _attr);
		}
		else if (!strcmp(szBufToken[0], "clear")) {
			clearScreenBuffer(0x2e, 0x0007);
		}
		else if (!strcmp(szBufToken[0], "lineV")) {
			int _xpos = atoi(szBufToken[1]);
			int _ypos = atoi(szBufToken[2]);
			int _length = atoi(szBufToken[3]);
			int _code = strtol(szBufToken[4], NULL, 16);
			int _attr = strtol(szBufToken[5], NULL, 16);
			drawLineV(_xpos, _ypos, _length, _code, _attr);
		}
		else if (!strcmp(szBufToken[0], "lineH")) {
			int _xpos = atoi(szBufToken[1]);
			int _ypos = atoi(szBufToken[2]);
			int _length = atoi(szBufToken[3]);
			int _code = strtol(szBufToken[4], NULL, 16);
			int _attr = strtol(szBufToken[5], NULL, 16);
			drawLineH(_xpos, _ypos, _length, _code, _attr);
		}
		else if (!strcmp(szBufToken[0], "triagle")) {
			int _xpos = atoi(szBufToken[1]);
			int _ypos = atoi(szBufToken[2]);
			int _length = atoi(szBufToken[3]);
			int _code = strtol(szBufToken[4], NULL, 16);
			int _attr = strtol(szBufToken[5], NULL, 16);
			drawTriangle(_xpos, _ypos, _length, _code, _attr);
		}

		updateBuffer(hdout);
	}

	return 0;
}