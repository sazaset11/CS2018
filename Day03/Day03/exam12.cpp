#include "stdafx.h"

int main()
{

	int i = 0;
	
	printf("while���� �̿�\n");
	
	while (i<10) {
		printf("%d\n", ++i);
	}
	
	printf("\nfor���� �̿�\n");

	for (int i = 1; i <= 10; i++) {
		printf("%d\n", i);
	}

	return 0;
}