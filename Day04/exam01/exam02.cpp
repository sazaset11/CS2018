#include "stdafx.h"

void output_gugudan(int Dan) {
	for (int i = 2; i < 10; i++) {
		printf("%d * %d = %2d    ", i, Dan, Dan*i);
	}
}

int main()
{
	int dan;

	for (dan = 1; dan < 10; dan++) {
		output_gugudan(dan);
		printf("\n");
	}

	return 0;
}