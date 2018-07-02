#include "stdafx.h"

void user_strcpy(char *des, const char *src) {
	while (*src) {
		*des = *src;
		src++;
		des++;
	}
}

int main() {
	char str[80] = {};

	user_strcpy(str, "straw berry");

	printf("%s\n", str);

	return 0;
}