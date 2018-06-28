#include "stdafx.h"

int main() {
	int i = 1;
	int a = 0, b = 0, c = 0;

	do
	{
		printf("πœ¿Ω");
		i++;
		a++;
	} while (i<5);
	printf("\n");
	
	i = 1;
	while (i < 5) {
		printf("º“∏¡");
		i++;
		b++;
	}
	printf("\n");

	i = 1;
	for (i; i < 10; i += 3) {
		printf("ªÁ∂˚");
		c++;
	}
	printf("\n%d, %d, %d\n", a, b, c);

	return 0;
}