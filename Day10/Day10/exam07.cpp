#include "stdafx.h"
#include "TGE.h"

extern CHAR_INFO g_chiBuffer[];

int main() {
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	clearScreenBuffer(g_chiBuffer);
	setCursor(hd, 0, 25);
	drawBox(2, 3, 10, 10, 0x00f0);
	drawLine(30, 5, 25, 0x00e0);
	drawTriagle(25, 8, 5, 0x00d0);

	updateBuffer(hd, g_chiBuffer);

	return 0;
}