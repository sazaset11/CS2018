// exam07.cpp: �ܼ� ���� ���α׷��� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	char sex;

	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%c", &sex);

	if (sex == 'm') {
		printf("�����Դϴ�.\n");
	}
	else if (sex == 'f') {
		printf("�����Դϴ�.\n");
	}
	else {
		printf("�߸� �Է��Ͽ����ϴ�.\n");
	}

	return 0;
}

