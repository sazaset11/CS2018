#include "stdafx.h"

double g_dbPI = 3.14;

struct _S_GAMEOBJECT
{
	char m_szName[16];
	int m_nHP;
};

void CreateObject(_S_GAMEOBJECT **pObj, const char *pName, int nHP) {
	*pObj = (_S_GAMEOBJECT*)malloc(sizeof(_S_GAMEOBJECT));
	(*pObj)->m_nHP = nHP;
	strcpy_s((*pObj)->m_szName, 16, pName);
}

void dumpObject(_S_GAMEOBJECT *pObj) {
	printf("%s, %d\n", pObj->m_szName, pObj->m_nHP);
}