#include "stdafx.h"

void str_prn(char text[5][80]) {
	printf("\n입력된 문장은...\n");
	printf("이름 : %s\n", text[0]);
	printf("성별 : %s\n", text[1]);
	printf("주소 : %s\n", text[2]);
	printf("직업 : %s\n", text[3]);
	printf("연봉 : %s\n", text[4]);
}

void str_input(char text [5][80]) {
	printf("다섯 개의 문장을 입력하세요.\n");
	printf("이름 : ");
	gets_s(text[0]);
	printf("성별 : ");
	gets_s(text[1]);
	printf("주소 : ");
	gets_s(text[2]);
	printf("직업 : ");
	gets_s(text[3]);
	printf("연봉 : ");
	gets_s(text[4]);
}

int main() {
	char input_text[5][80];
	char Buf[80];

	str_input(input_text);
	str_prn(input_text);

	return 0;
}