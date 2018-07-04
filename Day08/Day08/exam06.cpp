#include "stdafx.h"

void dump(char **strBuf) {
	for (int i = 0; strBuf[i]; i++) {
		printf("%s\n", strBuf[i]);
	}
}

int main() {
	char szCmdBuf[32];
	char *strBuf[100] = {};
	int count = 0;

	while (1) {
		printf("명령어 > ");
		gets_s(szCmdBuf, sizeof(szCmdBuf));

		if (!strcmp(szCmdBuf, "quit")) {
			for (int i = 0; i < count; i++) {
				free(strBuf[i]);
			}

			printf("프로그램을 종료합니다.\n");
			break;
		}
		else if (!strcmp(szCmdBuf, "add")) {
			char tmp[80] = {};

			printf("추가할 문장 입력 : ");
			gets_s(tmp, 80);
			//int ad = sizeof(tmp);
			strBuf[count] = (char*)malloc(strlen(tmp) + 1);
			strcpy_s(strBuf[count++], strlen(tmp) + 1, tmp);
			//printf("%d\n", count);
		}
		else if (!strcmp(szCmdBuf, "del")) {
			free(strBuf[--count]);
		}
		else if (!strcmp(szCmdBuf, "dump")) {
			dump(strBuf);
		}
		else {
			printf("실행할수 없는 명령어 입니다.\n");
		}
	}

	return 0;
}