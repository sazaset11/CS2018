#include "stdafx.h"

int main() {
	char *fruit = (char *)"strawberry";
	char fruit2[] = "strawberry";

	printf("%s\n", fruit);
	printf("%s\n", fruit + 2);

	//*(fruit + 3) = 'O';
	fruit2[3] = 'o';
	printf("%s\n", fruit2);

	return 0;
}