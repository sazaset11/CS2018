#include "stdafx.h"

int main() 
{
	char word[32];
	int count = 0;
	//A = 65, z=122

	printf("�ܾ �Է��ϼ��� : ");
	scanf_s("%s", word, sizeof(word));

	for (char check : word) {
		if (check == NULL) {
			break;
		}
		count++;
	}
	
	printf("%s�ܾ��� ���̴� %d���Դϴ�.\n", word, count);

	count = 0;
	for (char check : word) {
		if (check == NULL) {
			break;
		}
		if (check >= 65 && check <= 122) {
			count++;
		}
	}

	printf("%s�ܾ��� ���ĺ� ���� %d���Դϴ�.\n", word, count);

	return 0;
}