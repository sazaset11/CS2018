#include "stdafx.h"

int main()
{
	int a = 0;
	int sum = 0;

	while (a < 100) {
		//a = a + 1;
		//a += a;
		a++;

		printf("%d\n", a);
		
	}

	while (a >= 0) {
		printf("%d\n", a);
		a -= 10;
	}
	
	a = 0;
	while (a <= 100) {
		if ((a % 2) == 0) {
			printf("¦�� : %d\n", a);
		}
		else {
			printf("Ȧ�� : %d\n", a);
		}
		a++;
	}

	a = 0;
	while (a <= 100) {
		if ((a % 3) == 0) {
			sum += a;
		}
		a++;
	}
	printf("1~100���� 3�ǹ���� �� : %d\n", sum);

	return 0;
}