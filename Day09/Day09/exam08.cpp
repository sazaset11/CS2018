#include "stdafx.h"

int main() {
	int num;
	char name[20];

	fputs("���� �Է� : ", stdout);
	scanf_s("%d", &num);
	fputs("���ڿ� �Է� : ", stdout);
	scanf_s("%s", name, sizeof(name));

	printf("%d�� %s�� �Է��߽��ϴ�.\n", num, name);

	return 0;
}