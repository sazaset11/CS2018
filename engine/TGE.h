#pragma once

#define SCREEN_BUF_SIZE 2000
#define SCREEN_WIDTH 80
#define MAX_TOKEN_SIZE 64
namespace TGE {
	extern CHAR_INFO g_chiBuffer[];

	void setCursor(HANDLE, int, int);
	void setCharacter(CHAR_INFO*, int, int, WCHAR, WORD);
	void clearScreenBuffer(CHAR_INFO*,WCHAR, WORD);
	void copyScreenBuffer(CHAR_INFO*, CHAR_INFO*);
	void updateBuffer(HANDLE, CHAR_INFO*);
	void drawBox(CHAR_INFO*, int, int, int, int, WCHAR, WORD);
	void drawLineH(CHAR_INFO*, int, int, int, WCHAR, WORD);
	void drawLineV(CHAR_INFO*, int, int, int, WCHAR, WORD);
	void drawTriangle(CHAR_INFO*, int, int, int, WCHAR, WORD);
	int doTokenize(char*, char[8][MAX_TOKEN_SIZE]);
	CHAR_INFO *getCharacter(CHAR_INFO*, int, int);
	int loadBinary(CHAR_INFO*, const char*);
	int saveBinary(CHAR_INFO*, const char*);
	void putSprite(int, int, int, int, CHAR_INFO*, CHAR_INFO*);
	CHAR_INFO *CreateScreenBuffer();
	namespace util {
		UINT64 GetTimeMs64();
	}
	namespace input {
		extern char g_KeyTable[1024];
		extern COORD g_cdMousePos;
		void setNormalMode();
		void setEditMode();
		DWORD WINAPI MyThreadFunction(LPVOID);
	}
	void startTGE(HANDLE *phStdout);
	void endTGE();

}