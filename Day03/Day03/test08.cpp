#include "stdafx.h"

int main() {
	int a = 0;

	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			printf("%d * %d = %d\n", i, j, i*j);
			a++;
		}
	}
	printf("�ݺ� Ƚ�� %d\n", a);

	int i = 0;
	a = 0;
	while (i < 10) {
		for (int j = 1; j <= 10; j += 2) {
			printf("�ּ��� ���ϰ� �ϴ��� ���� ��ٸ���. \n");
			a++;
		}
		i++;
	}
	printf("�ݺ� Ƚ�� %d\n", a);

	return 0;
}