#include "stdafx.h"

void str_prn(char text[5][80]) {
	printf("\n�Էµ� ������...\n");
	printf("�̸� : %s\n", text[0]);
	printf("���� : %s\n", text[1]);
	printf("�ּ� : %s\n", text[2]);
	printf("���� : %s\n", text[3]);
	printf("���� : %s\n", text[4]);
}

void str_input(char text [5][80]) {
	printf("�ټ� ���� ������ �Է��ϼ���.\n");
	printf("�̸� : ");
	gets_s(text[0]);
	printf("���� : ");
	gets_s(text[1]);
	printf("�ּ� : ");
	gets_s(text[2]);
	printf("���� : ");
	gets_s(text[3]);
	printf("���� : ");
	gets_s(text[4]);
}

int main() {
	char input_text[5][80];
	char Buf[80];

	str_input(input_text);
	str_prn(input_text);

	return 0;
}