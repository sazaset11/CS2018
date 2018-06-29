#include "stdafx.h"
#include <stdlib.h>

char cTilteMap1[64] = {
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 2, 0, 0, 0, 1,
	1, 0, 0, 0, 9, 0, 0, 1,
	1, 1, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 3,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1
};

//char cTilteMap2[8][8]{
//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0 }
//};

int main() {
	/*for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d", cTilteMap2[i][j]);
		}
		printf("\n");
	}*/

	/*for (int i = 0; i < 64; i++) {
		printf("%d", cTilteMap1[i]);
	}*/
	char mov;
	int player = 29;
	while (1) {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				printf("%d ", cTilteMap1[x + y * 8]);
			}
			printf("\n");
		}

		scanf_s("%c", mov, sizeof(mov));
		switch (mov) {
		case 'w':
			player -= 8;
			break;
		case 's':
			player += 8;
			break;
		case 'a':
			player--;
			break;
		case 'd':
			player++;
			break;
		default:
			break;
		}

		system("cls");
	}
	

	//printf("\n");

	return 0;
}