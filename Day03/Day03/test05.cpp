#include "stdafx.h"

int main()
{
	int i;
	int sum = 0;

	for (i = 1; i <= 50; i++) {
		sum += i;
	}
	printf("for�� : sum = %d\n", sum);

	i = 1;
	sum = 0;
	while (i <= 50) {
		sum += i;
		i++;
	}
	printf("while�� : sum = %d\n", sum);

	return 0;
}