#include "stdafx.h"

int main()
{
	int age[5];
	int sum = 0;
	double avg;

	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &age[i]);
		sum += age[i];
	}
	avg = sum / 5.0;
	printf("5���� ������ �� : %d\n", sum);
	printf("5���� ������ ��� : %.1lf\n", avg);

	return 0;
}