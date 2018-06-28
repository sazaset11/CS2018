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
			printf("짝수 : %d\n", a);
		}
		else {
			printf("홀수 : %d\n", a);
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
	printf("1~100중의 3의배수의 합 : %d\n", sum);

	return 0;
}