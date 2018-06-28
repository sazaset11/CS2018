#include "stdafx.h"

int main()
{
	char word[] = { 'l', 'o', 'v', 'e' };

	for (char i : word) {
		printf("%c ", i);
	}

	printf("\n");

	return 0;
}