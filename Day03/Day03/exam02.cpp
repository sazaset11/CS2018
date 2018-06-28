// exam02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf("\x41\n");
	printf("☆★○●◎◇◆□■△▲▽▼→←↑↓\n");
	printf("부호 : %d, 부호없음 : %u\n", -1, -1);
	printf("십진수 : %d, 팔진수 : %o, 16진수 : %x\n", 16, 16, 16);
	printf("%x\n", '□');

	double _val = 0.0000031415926;
	printf("pi : %lf , %le\n", _val, _val);
	printf("%c , %s\n", 'H', "Hello");

	double a = 3.4;
	printf("%f, %d\n", a, a);

	int b, c;

	printf("두 정수를 입려하세요 : ");
	scanf_s("%d %d", &a, &b);
	printf("나눗셈 연산식은 \"%d / %d = %lf\"입니다.\n", a, b, (double)a / b);

	return 0;
}

