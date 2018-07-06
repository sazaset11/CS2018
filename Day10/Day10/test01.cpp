#include "stdafx.h"

void outputDec2Bin(int nDec) {
	int a = 0x80000000;

	//while (a < nDec) {
	//	a = a << 1;
	//}

	//if (a != nDec) a = a >> 1;

	while (a >= 1) {
		if (nDec&a) {
			printf("1");
		}
		else {
			printf("0");
		}
		a = a >> 1;
	}

	printf("\n");
}

int main() {
	int a;

	printf("정수 입력 : ");
	scanf_s("%d", &a);

	outputDec2Bin(a);

	return 0;
}