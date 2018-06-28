#include "stdafx.h"

int main()
{
	int a;

	printf("정수 입력 : ");
	scanf_s("%d", &a);
	printf("\n");

	for (int i = 0; i < a; i++) {
		for (int j = a + i; j > 0; j--) {
			if (j - 1 <= i*2) {
				printf("*");
			}
			else {
				printf(" ");
			}
			
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}