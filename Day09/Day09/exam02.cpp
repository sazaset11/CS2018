#include "stdafx.h"

struct score
{
	const char *name;
	int kor, eng, math;
};

int main() {
	score a;
	score *pa = &a;

	printf("%d, %d\n", sizeof(a), sizeof(pa));

	pa->name/* == (*pa).name*/ = "¾ÈÃ¶¼ö";
	pa->kor = 20;
	pa->eng = 30;
	pa->math = 50;

	printf("%s\n", pa->name);

	return 0;
}