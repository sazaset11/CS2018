// exam06.cpp: �ܼ� ���� ���α׷��� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int age;

	printf("���̸� �Է��ϼ��� : ");
	scanf_s("%d", &age);


	if (age < 0) {
		printf("���̸� ��Ȯ�ϰ� �Է��ϼ���.\n");
	}
	else if (age <= 6 || age >= 70) {
		printf("���������Դϴ�.\n");
	}
	else {
		printf("������ 3,000���Դϴ�.\n");
	}

	return 0;
}

