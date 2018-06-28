#include "stdafx.h"

int main()
{
	int a = 1;

	while (a) {
		printf("정수값을 입력하세요(0입력시 종료) : ");
		scanf_s("%d", &a);

		if (a < 0) a = -a;

		printf("절대값은 %d입니다.\n\n", a);
	}

	return 0;
}