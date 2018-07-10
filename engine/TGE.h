#pragma once

namespace tge {
	extern CHAR_INFO g_chiBuffer[];

	void setCursor(HANDLE, int, int);
	void setCharacter(int, int, WCHAR, WORD);
	void clearScreenBuffer(WCHAR, WORD);
	void updateBuffer(HANDLE);
	void drawBox(int, int, int, int, WCHAR, WORD);
	void drawLineH(int, int, int, WCHAR, WORD);
	void drawLineV(int, int, int, WCHAR, WORD);
	void drawTriangle(int, int, int, WCHAR, WORD);
	int doTokenize(char*, char[8][16]);
	CHAR_INFO *getCharacter(int, int);
	int loadBinary(const char*);
	int saveBinary(const char*);
}