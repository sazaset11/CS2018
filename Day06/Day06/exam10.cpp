#include "stdafx.h"

int main() {
	const char *str1 = "apple";
	char buf[64];

	strcpy_s(buf, str1);

	printf("%s\n%d\n", buf, strlen(buf));
	printf("���� ���ڿ� �ϴ� : %d\n", strcmp("cat", "cat"));
	printf("�ٸ� ���ڿ� �ϴ� : %d\n", strcmp("cat", "bat"));
	printf("�ٸ� ���ڿ� �ϴ� : %d\n", strcmp("cat", "dat"));

	strcat_s(buf, "pen");

	printf("%s\n", buf);

	return 0;
}