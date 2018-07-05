#include "stdafx.h"

int main() {
	FILE *fp;
	char ch;
	char szBuf[32];

	fopen_s(&fp, "a.txt", "w+");
	fputs("orc fighter, 100, 200, 70\n", fp);
	fclose(fp);
	fopen_s(&fp, "a.txt", "r+");
	fgets(szBuf, sizeof(szBuf), fp);

	printf("%s\n", szBuf);
	return 0;
}