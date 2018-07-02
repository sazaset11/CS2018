#include "stdafx.h"

int main() {
	int a;
	char szbuf[64];
	char c;

	scanf_s("%s", szbuf, 64);
	scanf_s("%c", &c);
	scanf_s("%d", &a);
	printf("%d %c %s\n", a, c, szbuf);

	return 0;
}