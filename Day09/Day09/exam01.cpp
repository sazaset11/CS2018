#include "stdafx.h"

struct profile
{
	int age;
	int height;
	const char *np;
};

struct student
{
	profile pf;
	int num;
	double grade;
};

int main() {
	student s1;
	s1.pf.np = "»´±Êµø";
	s1.pf.age = 55;
	s1.pf.height = 170;
	s1.num = 50;
	s1.grade = 9.0;
	profile pf1 = { 23,187,"æ»»Ò¡§" };
	student s2 = {
		{23, 187, "æ»»Ò¡§"},
		50, 9.0
	};

	printf("%d, %d, %s\n", pf1.age, pf1.height, pf1.np);
	printf("%d, %d, %s, %d, %lf\n", s2.pf.age, s2.pf.height, s2.pf.np, s2.num, s2.grade);

	return 0;
}