#include "stdafx.h"
#include "TGE.h"
//80*25 = 2000
extern CHAR_INFO g_chiBuffer[];

int main() {
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursor(hd, 0, 25);
	clearScreenBuffer(g_chiBuffer); 
	setCharacter(g_chiBuffer, 20, 3, 'A', 0x00cf);
	setCharacter(g_chiBuffer, 20, 4, 'B', 0x00cf);
	updateBuffer(hd, g_chiBuffer);	

	return 0;
}