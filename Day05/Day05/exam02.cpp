#include "stdafx.h"
#include <string>
//�迭�� �̿��Ͽ� que���� �����
int main()
{
	char szCmd[32];
	char cBufStack[256] = {};
	int top = 0;
	char tmp;

	while (1) {
		printf("Ŀ��带 �Է��ϼ��� : ");
		scanf_s("%s", szCmd, sizeof(szCmd));
		getchar();

		if (!strcmp(szCmd, "quit")) {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		else if (!strcmp(szCmd, "ins")) {
			printf("�����͸� �Է��ϼ��� : ");
			scanf_s("%c", &tmp, sizeof(tmp));
			printf("�Է°� : %c\n", tmp);
			cBufStack[top++] = tmp;
		}
		else if (!strcmp(szCmd, "del")) {
			if (!cBufStack[0]) {
				printf("������ ���ڰ� �����ϴ�.\n");
				break;
			}
			printf("���� ���� : %c\n", cBufStack[0]);
			for (int i = 0; i <= top; i++) {
				cBufStack[i] = cBufStack[i + 1];
			}
			top--;
		}
		else if (!strcmp(szCmd, "dump")) {
			printf("������ que : %s\n", cBufStack);
		}
		else {
			printf("�Է��Ͻ� Ŀ���� : %s �Դϴ�.\n", szCmd);
		}
		printf("==========================================\n");
	}

	return 0;
}