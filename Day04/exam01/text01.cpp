#include "stdafx.h"

int main()
{
	char word1[32];
	char word2[32] = {};
	int count = 0;

	printf("�ܾ �Է��ϼ��� : ");
	scanf_s("%s", word1, sizeof(word1));

	while (word1[count] != NULL) {
		count++;
	}

	int num = count;
	count -= 1;
	
	for (int i = 0; i < num; i++) {
		word2[i] = word1[count--];
	}

	printf("�ܾ �������� : %s\n", word2);

	return 0;
}