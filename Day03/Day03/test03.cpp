#include "stdafx.h"

int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 5 + i; j > 0; j--) {
			if (j - 1 <= i*2) {
				printf("*");
			}
			else {
				printf(" ");
			}
			
		}
		printf("\n");
	}

	return 0;
}