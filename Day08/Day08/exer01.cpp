#include "stdafx.h"

void str_prn(const char **ptr_ary, int count) {
	for (int i = 0; i < count; i++) {
		printf("%s\n", *(ptr_ary + i));
	}
}

int main() {
	const char *ptr_ary[] = { "eagle","tiger","lion","squirrel" };
	int count;

	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);

	str_prn(ptr_ary, count);

	return 0;
}