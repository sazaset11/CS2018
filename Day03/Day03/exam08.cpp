#include "stdafx.h"

int main() 
{
	int a, b;
	char _op;

	
	printf("�� ������ �Է� : ");
	scanf_s("%d %d", &a, &b);
	getchar();
	printf("��Ģ ������ ��ȣ�� �Է� : ");
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
		printf("��ȣ�� ��Ȯ�ϰ� �Է��ϼ���\n");
		break;
	}

	printf("%d  %c  %d = %d\n", a, _op, b, a * b);

	return 0;
}