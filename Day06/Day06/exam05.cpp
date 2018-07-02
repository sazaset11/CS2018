#include "stdafx.h"



//void ary_prn(int ap[])
//void ary_prn(int ap[5])
void ary_prn(int *ap) {
	printf("%d\n", sizeof(ap));
	for (int i = 0; i < 5; i++) {
		printf("%d ", ap[i]);
	}
	printf("\n");
}

int main() {
	int ary[5] = { 10,20,30,40,50 };
	/*int *ap = ary;
	
	printf("%d\n", *(ap + 2));*/
	printf("%d\n", sizeof(ary));
	ary_prn(ary);

	return 0;
}