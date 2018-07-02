#include "stdafx.h"

int sum1(int a, int b) {
	return a + b;
}

void sum2(int a, int b, int *d) {
	*d = a + b;
}

int main() {
	int c = sum1(1, 2);
	int d;

	sum2(1, 2, &d);

	printf("%d\n", c);
	printf("%d\n", d);

	return 0;
}