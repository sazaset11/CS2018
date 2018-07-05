#include "stdafx.h"

int main() {
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD _pos;
	char szBuf[64];
	_pos.X = 10;
	_pos.Y = 5;
	SetConsoleCursorPosition(hd, _pos);

	printf("login > ");
	gets_s(szBuf);

	_pos.X = 0;
	_pos.Y = 0;
	SetConsoleCursorPosition(hd, _pos);

	printf("%s ¥‘ ¡¢º”¡ﬂ...\n", szBuf);


	_pos.X = 0;
	_pos.Y = 29;
	SetConsoleCursorPosition(hd, _pos);

	return 0;
}