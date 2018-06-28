#include "stdafx.h"

int main()
{
	int nums[] = { 1,2,3 };

	int array_size = sizeof(nums) / sizeof(nums[0]);

	for (int i : nums) {
		printf("%5d", i);
	}
	printf("\n");

	return 0;
}