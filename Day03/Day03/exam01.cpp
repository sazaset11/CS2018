// exam01.cpp: �ܼ� ���� ���α׷��� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int inch, Celsius, mile;

	//printf("��ġ �Է� : ");
	//scanf_s("%d", &inch);
	//printf("���� �µ� �Է� : ");
	//scanf_s("%d", &Celsius);
	//printf("���� �Է� : ");
	//scanf_s("%d", &mile);

	printf("��ġ, ����, ���� ������ �Է��ϼ��� : ");
	scanf_s("%d %d %d", &inch, &Celsius, &mile);
	printf("\n================================================\n");
	printf("\t\t***����***\n\n");
	printf("%d ��ġ�� %.2lfcm �Դϴ�.\n", inch, inch*2.54);
	printf("%d ������ %.2lf ȭ�� �Դϴ�.\n", Celsius, Celsius*3.38);
	printf("%d ������ %d ��Ʈ �Դϴ�.\n", mile, mile * 5280);
	printf("================================================\n");



	return 0;
}

