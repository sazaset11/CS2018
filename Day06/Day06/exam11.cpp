#include "stdafx.h"


int main() {
	char str[80];
	char c;

	printf("문자열을 입력하세요 : ");
	gets_s(str);
	//printf("입력된 문자열 : %s\n", str);
	printf("입력된 문자열 : ");
	puts(str);

	printf("문자를 입력하세요 : ");
	c = getchar();
	putchar(c);
	printf("\n");
	
	return 0;
}