#include "stdafx.h"

int main()
{
	int ary[] = { 2,8,15,1,8,10,5,19,19,3,5,6,6,2,8,2,12,16,3,8,17,12,5,3,14,13,3,2,17,19,16,8,7,12,19,10,13,8,20,16,15,4,12,3,14,14,5,2,12,14,9,8,5,3,18,18,20,4 };
	int serchNum, count = 0;

	printf("찾기를 원하는 숫자를 입력하세요(1~20) : ");
	scanf_s("%d", &serchNum);

	for (int i : ary) {
		if (i == serchNum)	count++;
	}

	printf("숫자 %d은(는) 배열에 %d개 있습니다.\n", serchNum, count);

	return 0;
}