#include "stdafx.h"

int main() {
	FILE *fp;
	char ch;
	fopen_s(&fp, "b.txt", "w");

	if (!fp) {
		printf("파일읽기실패\n");
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