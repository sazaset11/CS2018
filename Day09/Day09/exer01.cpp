#include "stdafx.h"

struct profile
{
	char name[20];
	double grade;
	int english;
};

void input_data(profile *pf) {
	for (int i = 0; i < 5; i++) {
		scanf_s("%s %lf %d", (pf + i)->name, sizeof((pf + i)->name), &(pf + i)->grade, &(pf + i)->english);
	}
}

void elite(profile pf) {
	if (pf.english >= 900 && pf.grade >= 4.0) {
		printf("����Ʈ : %s, %.1lf, %d\n", pf.name, pf.grade, pf.english);
	}
}

int main() {
	profile new_staff[5];

	printf("�̸�, ����, ���������� �Է��ϼ���.\n");

	input_data(new_staff);
	
	printf("\n");

	for (int i = 0; i < 5; i++) {
		elite(new_staff[i]);
	}

	return 0;
}