#include "stdafx.h"

int main() {
	int a = 26;

	printf("%d\n", a & 0x10);

	a = 320;
	a >>= 5;

	printf("%d\n", a);

	return 0;
}