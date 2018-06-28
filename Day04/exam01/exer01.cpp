#include "stdafx.h"

void returnMax(double *a) {
	double max = 0;
	
	for (int i = 0; i < 5; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}

	printf("가장 큰 값은 : %lf입니다.\n", max);
}

void returnMin(double *a) {
	double min = 0;

	for (int i = 0; i < 5; i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}

	printf("가장 작은 값은 : %lf입니다.\n", min);
}

int main()
{
	double a[5];
	double max = 0;

	printf("다섯 개의 숫자를 입력하세요 : ");
	scanf_s("%lf %lf %lf %lf %lf", &a[0], &a[1], &a[2], &a[3], &a[4]);
	returnMax(a);
	returnMin(a);
	/*for (double i : a) {
		if (max < i) {
			max = i;
		}
	}*/

	return 0;
}