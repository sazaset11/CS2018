#include "stdafx.h"

int main() {
	const double pi = 3.14;
	int num = 5;
	const int *pNumReadOnly = NULL;
	pNumReadOnly = &num;

	printf("%.2lf, %d, %d\n", pi, num, *pNumReadOnly);

	num = 7;

	printf("%.2lf, %d, %d\n", pi, num, *pNumReadOnly);

	return 0;
}