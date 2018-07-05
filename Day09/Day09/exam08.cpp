#include "stdafx.h"

int main() {
	int num;
	char name[20];

	fputs("숫자 입력 : ", stdout);
	scanf_s("%d", &num);
	fputs("문자열 입력 : ", stdout);
	scanf_s("%s", name, sizeof(name));

	printf("%d와 %s를 입력했습니다.\n", num, name);

	return 0;
}