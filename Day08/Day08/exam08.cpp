#include "stdafx.h"

int main() {
	char strMsg[] = "move east and move north set 3,4";
	char *pTemp;
	//char *pToken = strMsg;
	const char *Delimiter = " ,";
	char *pToken = strtok_s(strMsg, Delimiter, &pTemp);

	//printf("%s\t%s\n", pToken, pTemp);

	while (pToken) {
		printf("%s\t%s\n", pToken, pTemp);
		pToken = strtok_s(NULL, Delimiter, &pTemp);
	}

	return 0;
}