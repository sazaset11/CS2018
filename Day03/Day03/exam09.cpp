#include "stdafx.h"

int main() {
	int date = 0;
	int hight = 0;
	
	do
	{
		date++;
		hight += 55;
		if (hight >= 300) {
			printf("%d��° Ż�� ����\n", date);
			break;
		}
		printf("%2d��° %3dcm �ö��\n", date, hight);
	} while (true);

	return 0;
}