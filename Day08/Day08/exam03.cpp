#include "stdafx.h"

int sum(int a, int b) {
	return a + b;
}

int _doit(int(*fp)(int, int), int a, int b) {
	return fp(a, b);
}

int main() {
	int(*fp)(int, int);
	fp = sum;
	printf("%d\n", sum(1, 2));
	printf("%d\n", fp(1, 2));
	printf("%d\n", _doit(sum, 1, 2));
	printf("%d\n", _doit(fp, 1, 2));

	return 0;
}