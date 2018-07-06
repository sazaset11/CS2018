#include "stdafx.h"

int main() {
	int a = 1, b = 2, c = 4, d = 8;

	char e = a | b | c | d;

	printf("%d %x\n", e, e);

	e = 9;// 1001
	for (int i = 0; i < 4; i++) {
		if (e&a) {
			printf("1");
		}
		else {
			printf("0");
		}
		a = a << 1;
	}

	printf("\n");

	char _e = b ^ c;
	
	printf("%d\n", _e);
	
	char k = 1;

	for (int i = 0; i < 5; i++) {
		k = k ^ 1;
		printf("%d\n", k);
	}

	return 0;
}