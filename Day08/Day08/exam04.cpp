#include "stdafx.h"



int main() {
	int *ip = NULL;
	
	ip = (int*)malloc(4);

	if (ip) {
		printf("�޸� �Ҵ� ����\n");
	}
	else {
		printf("�޸� ����\n");
	}

	*ip = 1;

	printf("%d\n", *ip);

	free(ip);

	return 0;
}