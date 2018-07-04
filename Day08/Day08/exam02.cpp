#include "stdafx.h"

void foo() {
	printf("i'm foo\n");
}

void bar() {
	printf("i'm bar\n");
}

int main() {
	void(*fp)();
	
	fp = foo;
	fp();

	fp = bar;
	fp();

	return 0;
}