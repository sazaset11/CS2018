#include "stdafx.h"

int main() {
	FILE *fp;
	char ch;
	fopen_s(&fp, "b.txt", "w");

	if (!fp) {
		printf("�����б����\n");
	}
	else {
		do
		{
			ch = getchar();
			fputc(ch, fp);
		} while (ch != EOF);
	}
	fclose(fp);

	return 0;
}