#include "stdafx.h"

enum season { spring = 1000, summer, fall, winter, rat=2000, cow, tiger, rabit, dragon, snake };

typedef int _BYTE32;

int main() {
	_BYTE32 myVal = 100;

	printf("%d\n", myVal);
	printf("%d %d %d %d\n", spring, summer, fall, winter);
	printf("%d %d %d %d\n", rat, cow, tiger, rabit);

	return 0;
}