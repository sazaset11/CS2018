#include "stdafx.h"

typedef struct SGAMEOBJECT
{
	char m_szName[32];
	int m_nHP;
	int m_nMP;
	int m_nATK;
	int m_nDEF;
}SGO;

void inputData(SGO *sgo, char *data) {
	const char *deli = " ";
	char *temp;
	char *pToken = strtok_s(data, deli, &temp);
	if (!temp) return;
	pToken = strtok_s(NULL, deli, &temp);
	strcpy_s(sgo->m_szName, sizeof(sgo->m_szName), pToken);
	pToken = strtok_s(NULL, deli, &temp);
	sgo->m_nHP = atoi(pToken);
	pToken = strtok_s(NULL, deli, &temp);
	sgo->m_nMP = atoi(pToken);
	pToken = strtok_s(NULL, deli, &temp);
	sgo->m_nATK = atoi(pToken);
	pToken = strtok_s(NULL, deli, &temp);
	sgo->m_nDEF = atoi(pToken);
}

void loadData(SGO *sgo) {

}

int main() {
	char szBuf[128];
	char szSaveData[128];
	FILE *fp;
	SGO player = {};

	

	while (true) {
		printf("명령어 > ");
		gets_s(szBuf, sizeof(szBuf));

		if (!strcmp(szBuf, "quit"))	break;
		else if (!strcmp(szBuf, "dump")) {
			printf("%s %d %d %d %d\n", player.m_szName, player.m_nHP, player.m_nMP, player.m_nATK, player.m_nDEF);
		}
		else if (!strncmp(szBuf, "edit", 4)) {
			//edit 이름 hp mp atk def
			inputData(&player, szBuf);
			
		}
		else if (!strcmp(szBuf, "save")) {
			char temp[64] = "";

			strcpy_s(temp, 64, player.m_szName);
			strcat_s(temp, 64, ".txt");

			fopen_s(&fp, temp, "w+");
			fprintf_s(fp, "edit %s %d %d %d %d\n", player.m_szName, player.m_nHP, player.m_nMP, player.m_nATK, player.m_nDEF);
			fclose(fp);			
		}
		else if (!strncmp(szBuf, "load", 4)) {
			const char *deli = " ";
			char *temp;
			char *pToken = strtok_s(szBuf, deli, &temp);

			strcat_s(temp, strlen(temp) + 5, ".txt");

			fopen_s(&fp, temp, "r");
			
			if (fp) {
				fgets(szSaveData, sizeof(szSaveData), fp);
				inputData(&player, szSaveData);
				fclose(fp);
			}
			else {
				printf("세이브 데이터가 없습니다.\n");
			}
		}
	}

	return 0;
}