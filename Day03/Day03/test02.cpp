#include "stdafx.h"

int main()
{
	int a = 1;

	while (a) {
		printf("�������� �Է��ϼ���(0�Է½� ����) : ");
		scanf_s("%d", &a);

		if (a < 0) a = -a;

		printf("���밪�� %d�Դϴ�.\n\n", a);
	}

	return 0;
}