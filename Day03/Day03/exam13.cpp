#include "stdafx.h"

int main()
{
	for (int i = 1; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			printf("%d * %d = %2d\t", j, i, j*i);
		}
		printf("\n");
	}

	return 0;
}