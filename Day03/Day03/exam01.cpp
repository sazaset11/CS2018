// exam01.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int inch, Celsius, mile;

	//printf("인치 입력 : ");
	//scanf_s("%d", &inch);
	//printf("섭씨 온도 입력 : ");
	//scanf_s("%d", &Celsius);
	//printf("마일 입력 : ");
	//scanf_s("%d", &mile);

	printf("인치, 섭씨, 마일 순으로 입력하세요 : ");
	scanf_s("%d %d %d", &inch, &Celsius, &mile);
	printf("\n================================================\n");
	printf("\t\t***보고서***\n\n");
	printf("%d 인치는 %.2lfcm 입니다.\n", inch, inch*2.54);
	printf("%d 섭씨는 %.2lf 화씨 입니다.\n", Celsius, Celsius*3.38);
	printf("%d 마일은 %d 피트 입니다.\n", mile, mile * 5280);
	printf("================================================\n");



	return 0;
}

