#include "stdafx.h"
using namespace tge;

int main() {
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	static char szCmdBuf[32];
	static char szTokenBuf[8][16];

	clearScreenBuffer(0x2e, 0x0007);
	updateBuffer(hd);

	while (1) {
		setCursor(hd, 0, 25);

		printf("																																						");

		setCursor(hd, 0, 25);

		printf("cmd > ");
		gets_s(szCmdBuf, sizeof(szCmdBuf));

		doTokenize(szCmdBuf, szTokenBuf);

		if (!strcmp(szTokenBuf[0], "quit")) {
			break;
		}

		updateBuffer(hd);
	}

	return 0;
}