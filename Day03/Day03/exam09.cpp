#include "stdafx.h"

int main() {
	int date = 0;
	int hight = 0;
	
	do
	{
		date++;
		hight += 55;
		if (hight >= 300) {
			printf("%d일째 탈출 성공\n", date);
			break;
		}
		printf("%2d일째 %3dcm 올라옴\n", date, hight);
	} while (true);

	return 0;
}