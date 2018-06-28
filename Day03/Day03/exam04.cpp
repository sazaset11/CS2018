// exam04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int main()
{
	char a, b;

	//scanf_s("%c %c", &a,sizeof(a),  &b,sizeof(b));
	cin >> a >> b;
	printf("입력 문자 : %c, %c\n", a, b);


	return 0;
}

