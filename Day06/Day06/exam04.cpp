#include "stdafx.h"

int main() {
	/*char ch;
	int in;
	double db;

	printf("char형 변수의 포인터 크기 : %d\n", sizeof(&ch));
	printf("int형 변수의 포인터 크기 : %d\n", sizeof(&in));
	printf("double형 변수의 포인터 크기 : %d\n", sizeof(&db));*/
	int ary[5] = { 10,20,30,40,50 };
	int *ap = ary;
	
	for (int i = 0; i < 5; i++) {
		printf("%d ", &ary[0] + i);
		printf("%d ", *(ap + i));
		printf("%d\n", *(ary + i));
	}
	/*for (int i : ary) {
		printf("%d ", i);
	}*/
	printf("\n");

	ap = &ary[2];

	for (int i = 0; i < 3; i++) {
		printf("%d ", ary[i + 2]);
		printf("%d\n", *(ap + i));
	}
	//printf("\n");

	return 0;
}