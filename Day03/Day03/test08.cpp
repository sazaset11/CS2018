#include "stdafx.h"

int main() {
	int a = 0;

	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			printf("%d * %d = %d\n", i, j, i*j);
			a++;
		}
	}
	printf("반복 횟수 %d\n", a);

	int i = 0;
	a = 0;
	while (i < 10) {
		for (int j = 1; j <= 10; j += 2) {
			printf("최선을 다하고 하늘의 뜻을 기다린다. \n");
			a++;
		}
		i++;
	}
	printf("반복 횟수 %d\n", a);

	return 0;
}