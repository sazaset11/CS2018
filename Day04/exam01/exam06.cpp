#include "stdafx.h"

int main() 
{
	char word[32];
	int count = 0;
	//A = 65, z=122

	printf("단어를 입력하세요 : ");
	scanf_s("%s", word, sizeof(word));

	for (char check : word) {
		if (check == NULL) {
			break;
		}
		count++;
	}
	
	printf("%s단어의 길이는 %d자입니다.\n", word, count);

	count = 0;
	for (char check : word) {
		if (check == NULL) {
			break;
		}
		if (check >= 65 && check <= 122) {
			count++;
		}
	}

	printf("%s단어의 알파벳 갯수 %d자입니다.\n", word, count);

	return 0;
}