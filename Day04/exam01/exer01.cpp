#include "stdafx.h"

void returnMax(double *a) {
	double max = 0;
	
	for (int i = 0; i < 5; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}

	printf("���� ū ���� : %lf�Դϴ�.\n", max);
}

void returnMin(double *a) {
	double min = 0;

	for (int i = 0; i < 5; i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}

	printf("���� ���� ���� : %lf�Դϴ�.\n", min);
}

int main()
{
	double a[5];
	double max = 0;

	printf("�ټ� ���� ���ڸ� �Է��ϼ��� : ");
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