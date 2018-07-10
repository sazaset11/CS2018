#include "stdafx.h"
#include "../../engine/TGE.h"
#include "maptool.h"

using namespace tge;

COORD g_cdCurrentCursorPos;
WCHAR g_wcCurrentBrushCode;
WORD g_wCurrentBrushAttr;
COORD _oldPos = { -1,-1 };
WCHAR _oldCode = -1;
WORD _oldAttr = -1;

void initMapTool() {
	g_cdCurrentCursorPos.X = 40;
	g_cdCurrentCursorPos.Y = 12;
	g_wcCurrentBrushCode = 0x20;
	g_wCurrentBrushAttr = 0x00e0;
}

int parseCmd(char *pzBuf) {
	FILE *fp;
	static char szTokenBuf[8][16];
	//토큰처리
	doTokenize(pzBuf, szTokenBuf);

	if (!strcmp(szTokenBuf[0], "quit"))	return 0;
	else if (!strcmp(szTokenBuf[0], "set")) {
		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[2]);
		WCHAR _code = (WCHAR)strtol(szTokenBuf[3], NULL, 16);
		WORD _attr = (WORD)strtol(szTokenBuf[4], NULL, 16);
		setCharacter(_xpos, _ypos, _code, _attr);
		
		return 1;
	}
	else if (!strcmp(szTokenBuf[0], "move")) {
		g_cdCurrentCursorPos.X = atoi(szTokenBuf[1]);
		g_cdCurrentCursorPos.Y = atoi(szTokenBuf[2]);
		
		return 1;
	}
	else if (!strcmp(szTokenBuf[0], "cursor")) {
		if (_oldPos.X >= 0) {
			setCharacter(_oldPos.X, _oldPos.Y, _oldCode, _oldAttr);
		}
		//이전값 대피
		_oldPos.X = g_cdCurrentCursorPos.X;
		_oldPos.Y = g_cdCurrentCursorPos.Y;
		CHAR_INFO *oldInfo = getCharacter(_oldPos.X, _oldPos.Y);
		_oldCode = oldInfo->Char.UnicodeChar;
		_oldAttr = oldInfo->Attributes;

		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[2]);
		WCHAR _code = (WCHAR)strtol(szTokenBuf[3], NULL, 16);
		WORD _attr = (WORD)strtol(szTokenBuf[4], NULL, 16);
		setCharacter(_xpos, _ypos, _code, _attr);

		return 1;
	}
	else if (!strcmp(szTokenBuf[0], "char")) {
		g_wcCurrentBrushCode = (WCHAR)strtol(szTokenBuf[1], NULL, 16);
		g_wCurrentBrushAttr = (WORD)strtol(szTokenBuf[2], NULL, 16);

		return 1;
	}
	else if (!strcmp(szTokenBuf[0], "clear")) {
		clearScreenBuffer(0x2e, 0x0007);

		return 1;
	}
	else if (!strcmp(szTokenBuf[0], "save")) {
		fopen_s(&fp, szTokenBuf[1], "w");
		fwrite(g_chiBuffer, 2000 * sizeof(CHAR_INFO), 1, fp);
		fclose(fp);

		return 1;
	}
	else if (!strcmp(szTokenBuf[0], "load")) {
		fopen_s(&fp, szTokenBuf[1], "r");
		if (fp) {
			fread_s(g_chiBuffer, 2000 * sizeof(CHAR_INFO), sizeof(CHAR_INFO), 2000, fp);
			fclose(fp);
		}

		return 1;
	}
	else return 1;
}