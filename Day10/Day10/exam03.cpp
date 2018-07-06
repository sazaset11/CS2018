#include "stdafx.h"
#include "gameobject2.h"

extern double g_dbPI;

int main() {
	_S_GAMEOBJECT *pPlayerObj = NULL;;

	CreateObject(&pPlayerObj, "no-name", 100);
	dumpObject(pPlayerObj);
	free(pPlayerObj);

	printf("%lf\n", g_dbPI);

	return 0;
}