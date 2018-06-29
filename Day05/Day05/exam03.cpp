#include "stdafx.h"
#include <time.h>
#include <string>

int main()
{
	char szCmd[32];
	char cBuf[256] = {};
	char tmp[32] = {};
	int head = 0, tail = 0, index;

	//add 문자열을 버퍼에 입력
	//del 특정위치 문자 삭제
	//inl 특정위치 문자 삽입
	//특정 위치에 문자열 삽입, 시작과 끝을 입력받아 그 사이의 문자 삭제

	while (1) {
		printf("명령어 > ");
		scanf_s("%s", szCmd, sizeof(szCmd));
		getchar();

		if (!strcmp(szCmd, "quit")) {
			printf("프로그램을 종료 합니다.\n");
			break;
		}
		else if (!strcmp(szCmd, "add")) {
			printf("데이터를 입력하세요 : ");
			scanf_s("%s", tmp, sizeof(tmp));
			printf("입력값 : %s\n", tmp);

			strcat_s(cBuf, tmp);
			tail += strlen(tmp);
		}
		else if (!strcmp(szCmd, "del")) {
			printf("삭제할 문자의 위치 입력 : ");
			scanf_s("%d", &index);
			printf("%d번째에 있는 문자 %c를 삭제\n", index, cBuf[index - 1]);

			for (int i = index - 1; i < tail; i++) {
				cBuf[i] = cBuf[i + 1];
			}
			
			tail--;
		}
		else if (!strcmp(szCmd, "inl")) {
			int count = 0;

			printf("문자열을 삽입할 위치 입력 : ");
			scanf_s("%d", &index);

			if (index > tail) {
				printf("문자열의 길이를 넘었습니다.\n");
			}
			else {
				printf("데이터를 입력하세요 : ");
				scanf_s("%s", tmp, sizeof(tmp));
				printf("입력값 : %s\n", tmp);

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
			printf("현재 Buffer : %s\ntail : %d\n", cBuf, tail);
		}
		printf("==========================================\n");
	}

	return 0;
}