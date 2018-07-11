#pragma once

#define SCREEN_BUF_SIZE 2000
#define SCREEN_WIDTH 80
#define MAX_TOKEN_SIZE 64
namespace tge {
	extern CHAR_INFO g_chiBuffer[];

	void setCursor(HANDLE, int, int);
	void setCharacter(CHAR_INFO*, int, int, WCHAR, WORD);
	void clearScreenBuffer(WCHAR, WORD);
	void updateBuffer(HANDLE);
	void drawBox(CHAR_INFO*, int, int, int, int, WCHAR, WORD);
	void drawLineH(CHAR_INFO*, int, int, int, WCHAR, WORD);
	void drawLineV(CHAR_INFO*, int, int, int, WCHAR, WORD);
	void drawTriangle(CHAR_INFO*, int, int, int, WCHAR, WORD);
	int doTokenize(char*, char[8][MAX_TOKEN_SIZE]);
	CHAR_INFO *getCharacter(CHAR_INFO*, int, int);
	int loadBinary(CHAR_INFO*, const char*);
	int saveBinary(CHAR_INFO*, const char*);
	CHAR_INFO *CreateScreenBuffer();
}