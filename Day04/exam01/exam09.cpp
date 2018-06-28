#include "stdafx.h"
#include <string>

int main()
{
	char word1[100];
	char word2[100] = {};
	bool check = false;
	int i = 0;
	/*int a = 1, b = 2;
	int *pa, *pb;
	pa = &a;
	pb = &b;
	printf("%d\n%d\n%d\n", a, b, pa - pb);*/

	scanf_s("%s", word1, sizeof(word1));
	strcpy_s(word2, word1);
	//printf("%s\n%s\n", word1, word2);

	while (word1[i] != NULL) {
		if (word1[i] == '@') {
			if (!check) {
				check = true;
				i++;
			}
			else {
				check = false;
			}
		}
		if (check) {
			word1[i] = '*';
		}
		i++;
	}

	printf("%s\n", word1);

	int count = 0;
	for (char test : word2) {
		if (test == '@') count++;
	}
	if (count >= 2) {
		char *pch1;
		char *pch2;

		pch1 = strchr(word2, '@');
		pch2 = strrchr(word2, '@');
		int min = pch1 - word2;
		int max = pch2 - word2;

		for (int i = min; i <= max; i++) {
			if (word2[i] != '@') {
				word2[i] = '*';
			}
		}

		printf("%s\n", word2);
	}
	else {
		printf("@를 2개이상 입력하세요\n");
	}

	return 0;
}