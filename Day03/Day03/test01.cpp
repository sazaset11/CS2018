#include "stdafx.h"


int main() {
	char name[10];
	int kor, math, eng, sum;
	//double aver;

	printf("�̸� �Է� : ");
	scanf_s("%s", name, sizeof(name));
	printf("����, ����, ���� ���� �Է� : ");
	scanf_s("%d %d %d", &kor, &eng, &math);
	sum = kor + eng + math;
	printf("|----------|--------|--------|--------|--------|----------|\n");
	printf("|   �̸�   |  ����  |  ����  |  ����  |  ����  |   ���   |\n");
	printf("|----------|--------|--------|--------|--------|----------|\n");
	printf("|%-10s|%8d|%8d|%8d|%8d|%10.2lf|\n", name, kor, eng, math, sum, sum / 3.0);
	printf("|----------|--------|--------|--------|--------|----------|\n");


	return 0;
}