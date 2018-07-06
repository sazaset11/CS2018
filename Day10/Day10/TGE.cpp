#include "stdafx.h"
#define SCREEN_BUF_SIZE 2000
#define SCREEN_WIDTH 80

CHAR_INFO g_chiBuffer[SCREEN_BUF_SIZE];

void setCursor(HANDLE hd, int x, int y) {
	COORD _pos;
	_pos.X = x;
	_pos.Y = y;
	SetConsoleCursorPosition(hd, _pos);
}

void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WCHAR attr) {
	pBuf[80 * y + x].Char.UnicodeChar = code;
	pBuf[80 * y + x].Attributes = attr;
}

void clearScreenBuffer(CHAR_INFO *pBuf) {
	for (int i = 0; i < SCREEN_BUF_SIZE; i++) {
		pBuf[i].Char.UnicodeChar = 9673;//9678
		pBuf[i].Attributes = 0x009f;
	}
}

void updateBuffer(HANDLE hd, CHAR_INFO *pBuf) {
	COORD coordBufSize;
	COORD coordBufferCoord;
	coordBufSize.X = 80;
	coordBufSize.Y = 25;
	coordBufferCoord.X = 0;
	coordBufferCoord.Y = 0;
	SMALL_RECT destRect;
	destRect.Top = 0;
	destRect.Left = 0;
	destRect.Right = destRect.Left + coordBufSize.X - 1;
	destRect.Bottom = destRect.Top + coordBufSize.Y - 1;
	WriteConsoleOutput(hd, pBuf, coordBufSize, coordBufferCoord, &destRect);
}

void drawBox(int x, int y, int width, int height, WCHAR code) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			setCharacter(g_chiBuffer, x + j, y + i, 0x20, code);
		}
	}
}

void drawLine(int x, int y, int length, WCHAR code) {
	for (int i = 0; i < length; i++) {
		setCharacter(g_chiBuffer, x + i, y, 0x20, code);
	}
}

void drawTriagle(int x, int y, int height, WCHAR code) {
	for (int i = 0; i < height; i++) {
		int a = height - 1;

		for (int j = height + i; j > 0; j--) {
			if (j - 1 <= i * 2) {
				setCharacter(g_chiBuffer, x + a, y + i, 0x20, code);
			}
			a--;
		}
	}
}