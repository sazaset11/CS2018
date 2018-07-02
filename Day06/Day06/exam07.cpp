#include "stdafx.h"

int main() {
	char str1[80] = "dream1";
	const char *str2 = "dream2";
	char str3[] = "dream3";
	char *str4;

	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	

	return 0;
}