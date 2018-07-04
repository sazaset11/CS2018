#include "stdafx.h"

int main() {
	int *pa = (int*)malloc(sizeof(int) * 5);;
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &pa[i]/* == pa + i*/);
		sum += *(pa + i)/* == pa[i]*/;
	}

	printf("%lf\n", sum / 5.0);

	free(pa);

	return 0;
}