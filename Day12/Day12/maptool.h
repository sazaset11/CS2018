#pragma once

extern COORD g_cdCurrentCursorPos;
extern COORD _oldPos;
extern WCHAR g_wcCurrentBrushCode;
extern WORD g_wCurrentBrushAttr;

int parseCmd(char *pzBuf);
void initMapTool();