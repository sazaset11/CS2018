// exam03.cpp: �ܼ� ���� ���α׷��� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	printf("%d\n", 1234);
	printf("%10d\n", 1234);

	int a = 10;
	double b = 3.0;
	double c = a / b;

	printf("%lf\n", c);
	printf("%10lf\n", c);

	printf("%s######\n", "Hello");
	printf("%10s######\n", "Hello");
	printf("%-10s######\n", "Hello");

	return 0;
}

