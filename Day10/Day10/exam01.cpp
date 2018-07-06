#include "stdafx.h"

#define SUM(x,y) x+y
#define PI 3.141592
const double _PI = 3.141592;


int main() {
	printf("%lf, %d, %lf\n", PI, SUM(3,4), SUM(3.4,6.5));

#ifdef _MY_TEST
	printf("hello define\n");
#elif _MY_TEST2
	printf("hello test2 define\n");
#else
	printf("hello not define\n");
#endif // _MY_TEST


	return 0;
}