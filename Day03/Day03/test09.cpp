#include "stdafx.h"

int main() {
	int i, sum = 0;

	for(i = 1; i <= 20; i++) {
		if (i % 3 == 0)	continue;
		sum += i;
		if (sum > 15)	break;
		printf("i => %3d, sum => %3d\n", i, sum);
	}

	return 0;
}