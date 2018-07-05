#include "stdafx.h"

union student {
	int num;
	double grade;
};

int main() {
	student a;
	a.num = 10;

	printf("%d %lf\n", a.num, a.grade);
	printf("%d %d\n", &a.num, &a.grade);

	student b;
	b.grade = 10.0;

	printf("%d %lf\n", b.num, b.grade);
	printf("%d %d\n", &b.num, &b.grade);
	printf("%d\n", sizeof(student));

	void *pUnion;
	pUnion = malloc(8);
	*(int*)pUnion = 10;

	printf("%d %lf\n", *(int*)pUnion, *(double*)pUnion);

	*(double*)pUnion = 10.0;

	printf("%d %lf\n", *(int*)pUnion, *(double*)pUnion);

	return 0;
}