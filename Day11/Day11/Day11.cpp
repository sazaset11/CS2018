// Day11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

using namespace tge;


int main()
{
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	clearScreenBuffer(0x2e, 0x000f);

	drawLineH(5, 5, 20, 0x20, 0x00c0);
	drawLineH(5, 6, 19, 0x20, 0x00a0);
	drawLineV(4, 5, 10, 0x20, 0x00f0);

	setCursor(hd, 0, 25);
	tge::updateBuffer(hd);


    return 0;
}

