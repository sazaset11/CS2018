#include "stdafx.h"

int main() {
	const char *str1 = "apple";
	char buf[64];

	strcpy_s(buf, str1);

	printf("%s\n%d\n", buf, strlen(buf));
	printf("같은 문자열 일대 : %d\n", strcmp("cat", "cat"));
	printf("다른 문자열 일대 : %d\n", strcmp("cat", "bat"));
	printf("다른 문자열 일대 : %d\n", strcmp("cat", "dat"));

	strcat_s(buf, "pen");

	printf("%s\n", buf);

	return 0;
}