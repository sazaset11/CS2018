#include "stdafx.h"


int main() {
	char str[80];
	char c;

	printf("���ڿ��� �Է��ϼ��� : ");
	gets_s(str);
	//printf("�Էµ� ���ڿ� : %s\n", str);
	printf("�Էµ� ���ڿ� : ");
	puts(str);

	printf("���ڸ� �Է��ϼ��� : ");
	c = getchar();
	putchar(c);
	printf("\n");
	
	return 0;
}