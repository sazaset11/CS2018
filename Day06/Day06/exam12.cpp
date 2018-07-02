#include "stdafx.h"

int main() {
	char szBuf[8];

	for (int i = 0; i < 8; i++) {
		szBuf[i] = getchar();
	}

	printf("%s\n", szBuf);

	return 0;
}