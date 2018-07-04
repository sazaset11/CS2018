#include "stdafx.h"

int main() {
	int ary[3][4] = { {1,2,3,4,},{5,6,7,8,},{9,10,11,12} };

	printf("%8d% 8d\n", (*ary)[0], (*ary + 1)[0]);
	printf("%8d% 8d\n", *ary, *ary + 1);
	printf("%8d% 8d\n", *ary[0], *ary[1]);
	printf("%8d% 8d\n", ary, ary + 1);
	printf("%8d% 8d\n", &ary, &ary + 1);

	return 0;
}