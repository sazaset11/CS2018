#include "stdafx.h"
#include "../../engine/TGE.h"

int main() {
	HANDLE hdout = GetStdHandle(STD_OUTPUT_HANDLE);
	tge::loadBinary("1.map");

	tge::updateBuffer(hdout);

	return 0;
}