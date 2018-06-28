#include "stdafx.h"

int main() 
{
	int a, b;
	char _op;

	
	printf("두 정수를 입력 : ");
	scanf_s("%d %d", &a, &b);
	getchar();
	printf("사칙 연산의 기호를 입력 : ");
	scanf_s("%c", &_op);
	
	switch (_op)
	{
	case '+':
		printf("%d  %c  %d = %d\n", a, _op, b, a + b);
		break;
	case '-':
		printf("%d  %c  %d = %d\n", a, _op, b, a - b);
		break;
	case '*':
		printf("%d  %c  %d = %d\n", a, _op, b, a * b);
		break;
	case '/':
		printf("%d  %c  %d = %.2lf\n", a, _op, b, (double)a / b);
		break;
	default:
		printf("기호를 정확하게 입력하세요\n");
		break;
	}

	printf("%d  %c  %d = %d\n", a, _op, b, a * b);

	return 0;
}