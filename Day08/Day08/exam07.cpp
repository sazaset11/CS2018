#include "stdafx.h"

int main(int argc, char **argv) {
	printf("인자수는 : %d\n", argc);
	
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	
	return 0;
}