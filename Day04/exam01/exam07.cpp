#include "stdafx.h"

int main()
{
	/*���ڿ��� �Է¹����� ���ĺ��� *�κ�ȯ*/
	char word[32];
	int i = 0;
	//A = 65, z=122

	printf("�ܾ �Է��ϼ��� : ");
	scanf_s("%s", word, sizeof(word));

	/*for (char check : word) {
		if (check == NULL) {
			break;
		}
		if (check >= 65 && check <= 122) {
			word[i] = '*';
		}
		i++;
	}*/
	while (word[i] != NULL) {
		if (word[i] >= 65 && word[i] <= 122) {
			word[i] = '*';
		}
		i++;
	}

	printf("%s\n", word);

	return 0;
}