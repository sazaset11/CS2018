#include "stdafx.h"
#include <time.h>
#include <string>

int main()
{
	char szCmd[32];
	char cBuf[256] = {};
	char tmp[32] = {};
	int head = 0, tail = 0, index;

	//add ���ڿ��� ���ۿ� �Է�
	//del Ư����ġ ���� ����
	//inl Ư����ġ ���� ����
	//Ư�� ��ġ�� ���ڿ� ����, ���۰� ���� �Է¹޾� �� ������ ���� ����

	while (1) {
		printf("��ɾ� > ");
		scanf_s("%s", szCmd, sizeof(szCmd));
		getchar();

		if (!strcmp(szCmd, "quit")) {
			printf("���α׷��� ���� �մϴ�.\n");
			break;
		}
		else if (!strcmp(szCmd, "add")) {
			printf("�����͸� �Է��ϼ��� : ");
			scanf_s("%s", tmp, sizeof(tmp));
			printf("�Է°� : %s\n", tmp);

			strcat_s(cBuf, tmp);
			tail += strlen(tmp);
		}
		else if (!strcmp(szCmd, "del")) {
			printf("������ ������ ��ġ �Է� : ");
			scanf_s("%d", &index);
			printf("%d��°�� �ִ� ���� %c�� ����\n", index, cBuf[index - 1]);

			for (int i = index - 1; i < tail; i++) {
				cBuf[i] = cBuf[i + 1];
			}
			
			tail--;
		}
		else if (!strcmp(szCmd, "inl")) {
			int count = 0;

			printf("���ڿ��� ������ ��ġ �Է� : ");
			scanf_s("%d", &index);

			if (index > tail) {
				printf("���ڿ��� ���̸� �Ѿ����ϴ�.\n");
			}
			else {
				printf("�����͸� �Է��ϼ��� : ");
				scanf_s("%s", tmp, sizeof(tmp));
				printf("�Է°� : %s\n", tmp);

				while (tmp[count]) {
					count++;
				}

				if (index == tail) {
					for (int i = 0; i <= count; i++) {
						cBuf[tail + i] = tmp[i];
					}
				}
				else {
					index--;

					for (int i = tail; i >= index; i--) {
						cBuf[i + count] = cBuf[i];
					}

					for (int i = 0; i < count; i++) {
						cBuf[index + i] = tmp[i];
					}
				}				
				
				tail += count;
			}
		}
		else if (!strcmp(szCmd, "dump")) {
			printf("���� Buffer : %s\ntail : %d\n", cBuf, tail);
		}
		printf("==========================================\n");
	}

	return 0;
}