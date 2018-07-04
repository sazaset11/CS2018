#include "stdafx.h"
#include <Windows.h>

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	WORD wOldColoerAttr;

	GetConsoleScreenBufferInfo(hConsole, &csbInfo);

	wOldColoerAttr = csbInfo.wAttributes;

	//0000		0000
	//8421		8421
	//(back)	(fore)
	//iRGB		iRGB
	SetConsoleTextAttribute(hConsole, 0x1e);
	printf("HELLO\n");
	SetConsoleTextAttribute(hConsole, 0x29);
	printf("WORLD\n");
	SetConsoleTextAttribute(hConsole, wOldColoerAttr);
	

	return 0;
}