#include "stdafx.h"

int main()
{

	int i = 0;
	
	printf("while문을 이용\n");
	
	while (i<10) {
		printf("%d\n", ++i);
	}
	
	printf("\nfor문을 이용\n");

	for (int i = 1; i <= 10; i++) {
		printf("%d\n", i);
	}

	return 0;
}