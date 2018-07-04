#include "stdafx.h"

int main() {
	const char *szMsg = "hello world";
	char *pTemp;

	pTemp = (char*)malloc(7);
	//strcpy_s(pTemp, strlen(szMsg) + 1, szMsg);
	memcpy(pTemp, &szMsg[4], 6);
	pTemp[6] = NULL;

	printf("%s\n", pTemp);

	return 0;
}