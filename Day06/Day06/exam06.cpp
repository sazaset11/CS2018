#include "stdafx.h"

void prt_Min(double *ap, int size) {
	double min = ap[0];

	for (int i = 0; i < size; i++) {
		if (min > ap[i])	min = ap[i];
	}

	printf("�迭�� �ּڰ� : %.2lf\n", min);
}

void prt_Max(double *ap, int size) {
	double max = ap[0];

	for (int i = 0; i < size; i++) {
		if (max < ap[i])	max = ap[i];
	}

	printf("�迭�� �ִ밪 : %.2lf\n", max);
}

int main() {
	double ary[] = { 16.4,2.3,3.5,1.5,20.1 };
	int size = sizeof(ary) / sizeof(double);

	prt_Min(ary, size);
	prt_Max(ary, size);

	return 0;
}