#include "stdafx.h"

int main() {
	int i = 1;
	int a = 0, b = 0, c = 0;

	do
	{
		printf("����");
		i++;
		a++;
	} while (i<5);
	printf("\n");
	
	i = 1;
	while (i < 5) {
		printf("�Ҹ�");
		i++;
		b++;
	}
	printf("\n");

	i = 1;
	for (i; i < 10; i += 3) {
		printf("���");
		c++;
	}
	printf("\n%d, %d, %d\n", a, b, c);

	return 0;
}