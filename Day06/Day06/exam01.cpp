#include "stdafx.h"

int main()
{
	int num[5] = { 1, 2, 3, 4, 5 };

	printf("%8d, %8d, %8d, %8d, %8d\n", num[0], num[1], num[2], num[3], num[4]);
	printf("%8d, %8d, %8d, %8d, %8d\n", &num[0], &num[1], &num[2], &num[3], &num[4]);

	return 0;
}