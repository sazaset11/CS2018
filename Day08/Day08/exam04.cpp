#include "stdafx.h"



int main() {
	int *ip = NULL;
	
	ip = (int*)malloc(4);

	if (ip) {
		printf("메모리 할당 성공\n");
	}
	else {
		printf("메모리 부족\n");
	}

	*ip = 1;

	printf("%d\n", *ip);

	free(ip);

	return 0;
}