#include "stdafx.h"

int main()
{
	char word[32];
	int count = 0;

	printf("단어를 입력하세요 : ");
	scanf_s("%s", word, sizeof(word));

	while (word[count] != NULL) {
		count++;
	}
	
	int num = count / 2;
	count -= 1;
	
	
	for (int i = 0; i < num; i++) {
		char tmp = word[i];
		word[i] = word[count];
		word[count--] = tmp;
	}
	
	printf("단어를 뒤집으면 : %s\n", word);

	return 0;
}