// Day06.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int num;
	int *ptr;
	num = 3;
	ptr = &num;

	printf("%d %d\n", num, &num);
	printf("%d %d\n", *ptr, ptr);

	*ptr = 5;

	printf("%d %d\n", num, &num);
	printf("%d %d\n", *ptr, ptr);

	int address;

	scanf_s("%d", &address);
	printf("%d %d\n", address, *((int*)address));

    return 0;
}

