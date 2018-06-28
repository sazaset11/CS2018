#include "stdafx.h"

int main()
{
	int i = 1;
	int a = 0;

	while (i++ < 10) {
		printf("뇌를 자극하는 C프로그래밍\n");
		a++;
	}

	printf("%d회 반복 i의 값 : %d\n", a, i);

	return 0;
}