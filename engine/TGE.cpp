#include "stdafx.h"

#define SCREEN_BUF_SIZE 2000
#define SCREEN_WIDTH 80

namespace tge {


	CHAR_INFO g_chiBuffer[SCREEN_BUF_SIZE];

	void setCursor(HANDLE hdout, int x, int y) {
		COORD _pos;
		_pos.X = x;
		_pos.Y = y;
		SetConsoleCursorPosition(hdout, _pos);
	}

	void setCharacter(int x, int y, WCHAR code, WORD attr) {
		CHAR_INFO *pBuf = g_chiBuffer;
		pBuf[80 * y + x].Char.UnicodeChar = code;
		pBuf[80 * y + x].Attributes = attr;
	}

	void clearScreenBuffer(WCHAR code, WORD attr) {
		CHAR_INFO *pBuf = g_chiBuffer;
		for (int i = 0; i < SCREEN_BUF_SIZE; i++) {
			pBuf[i].Char.UnicodeChar = code;//9678
			pBuf[i].Attributes = attr;
		}
	}

	void updateBuffer(HANDLE hdout) {
		COORD coordBufSize;
		COORD coordBufferCoord;
		coordBufSize.X = 80;
		coordBufSize.Y = 25;
		coordBufferCoord.X = 0;
		coordBufferCoord.Y = 0;
		SMALL_RECT destRect;
		CHAR_INFO *pBuf = g_chiBuffer;
		destRect.Top = 0;
		destRect.Left = 0;
		destRect.Right = destRect.Left + coordBufSize.X - 1;
		destRect.Bottom = destRect.Top + coordBufSize.Y - 1;
		WriteConsoleOutput(hdout, pBuf, coordBufSize, coordBufferCoord, &destRect);
	}

	void drawBox(int x, int y, int width, int height, WCHAR code, WORD attr) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setCharacter(x + j, y + i, code, attr);
			}
		}
	}

	void drawLineH(int x, int y, int length, WCHAR code, WORD attr) {
		for (int i = 0; i < length; i++) {
			setCharacter(x + i, y, code, attr);
		}
	}

	void drawLineV(int x, int y, int length, WCHAR code, WORD attr) {
		for (int i = 0; i < length; i++) {
			setCharacter(x, y + i, code, attr);
		}
	}

	void drawTriangle(int x, int y, int height, WCHAR code, WORD attr) {
		for (int i = 0; i < height; i++) {
			int a = height - 1;

			for (int j = height + i; j > 0; j--) {
				if (j - 1 <= i * 2) {
					setCharacter(x + a, y + i, code, attr);
				}
				a--;
			}
		}
	}

	int doTokenize(char *szBuf, char szBufToken[8][16]) {
		char *szpTemp;
		char *pNextToken = NULL;
		const char *pzDelimiter = " ";
		int _nTokenIndex = 0;

		szpTemp = strtok_s(szBuf, pzDelimiter, &pNextToken);

		while (szpTemp) {
			strcpy_s(szBufToken[_nTokenIndex++], sizeof(szBufToken[_nTokenIndex]), szpTemp);
			szpTemp = strtok_s(NULL, pzDelimiter, &pNextToken);
		}

		/*printf("ÅäÅ« ¼ö : %d\n", _nTokenIndex);

		for (int i = 0; i < _nTokenIndex; i++) {
		printf("%s\n", szBufToken[i]);
		}*/
		return _nTokenIndex;
	}
}