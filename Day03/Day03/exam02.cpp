// exam02.cpp: �ܼ� ���� ���α׷��� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	printf("\x41\n");
	printf("�١ڡۡܡݡޡߡ����������\n");
	printf("��ȣ : %d, ��ȣ���� : %u\n", -1, -1);
	printf("������ : %d, ������ : %o, 16���� : %x\n", 16, 16, 16);
	printf("%x\n", '��');

	double _val = 0.0000031415926;
	printf("pi : %lf , %le\n", _val, _val);
	printf("%c , %s\n", 'H', "Hello");

	double a = 3.4;
	printf("%f, %d\n", a, a);

	int b, c;

	printf("�� ������ �Է��ϼ��� : ");
	scanf_s("%d %d", &a, &b);
	printf("������ ������� \"%d / %d = %lf\"�Դϴ�.\n", a, b, (double)a / b);

	return 0;
}

