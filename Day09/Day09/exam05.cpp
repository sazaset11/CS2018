#include "stdafx.h"

int main() {
	FILE *fp;
	char ch;
	 
	fopen_s(&fp, "exer01.cpp", "r");

	if (!fp) {
		printf("�����б����\n");
	}
	else {
		do
		{
			ch = fgetc(fp);
			printf("%c", ch);
		} while (ch!=EOF);
		printf("\n");
		fclose(fp);
	}

	return 0;
}