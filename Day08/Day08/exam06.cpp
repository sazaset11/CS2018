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
		printf("��ɾ� > ");
		gets_s(szCmdBuf, sizeof(szCmdBuf));

		if (!strcmp(szCmdBuf, "quit")) {
			for (int i = 0; i < count; i++) {
				free(strBuf[i]);
			}

			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		else if (!strcmp(szCmdBuf, "add")) {
			char tmp[80] = {};

			printf("�߰��� ���� �Է� : ");
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
			printf("�����Ҽ� ���� ��ɾ� �Դϴ�.\n");
		}
	}

	return 0;
}