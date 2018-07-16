#include "stdafx.h"
#include "maptool_struct.h"
#include "TGE.h"

namespace TGE {
	CHAR_INFO g_chiBuffer[SCREEN_BUF_SIZE];
	DWORD dwThreadId_ReadInput;
	HANDLE hThread_ReadInput;

	CHAR_INFO *CreateScreenBuffer() {
		return (CHAR_INFO *)malloc(sizeof(CHAR_INFO) * SCREEN_BUF_SIZE);
	}


	void setCursor(HANDLE hdout, int x, int y) {
		COORD _pos;
		_pos.X = x;
		_pos.Y = y;
		SetConsoleCursorPosition(hdout, _pos);
	}

	void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WORD attr) {

		pBuf[80 * y + x].Char.UnicodeChar = code;
		pBuf[80 * y + x].Attributes = attr;
	}

	CHAR_INFO *getCharacter(CHAR_INFO *pBuf, int x, int y) {
		return &(pBuf[80 * y + x]);
	}

	void clearScreenBuffer(CHAR_INFO *pBuf, WCHAR code, WORD attr) {
		for (int i = 0; i < SCREEN_BUF_SIZE; i++) {
			pBuf[i].Char.UnicodeChar = code;//9678
			pBuf[i].Attributes = attr;
		}
	}

	void copyScreenBuffer(CHAR_INFO *pBufdest, CHAR_INFO *pBufsrc)
	{
		memcpy_s(pBufdest, SCREEN_BUF_SIZE * sizeof(CHAR_INFO),
			pBufsrc, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));
	}

	void updateBuffer(HANDLE hdout, CHAR_INFO *pBuf) {
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
		WriteConsoleOutput(hdout, pBuf, coordBufSize, coordBufferCoord, &destRect);
	}

	void drawBox(CHAR_INFO *pBuf, int x, int y, int width, int height, WCHAR code, WORD attr) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				int _x = x + j;

				if (_x > 79) _x = 79;

				int _y = y + i;

				if (_y > 24) _y = 24;

				setCharacter(pBuf, _x, _y, code, attr);
			}
		}
	}

	void drawLineH(CHAR_INFO *pBuf, int x, int y, int length, WCHAR code, WORD attr) {
		for (int i = 0; i < length; i++) {
			setCharacter(pBuf, x + i, y, code, attr);
		}
	}

	void drawLineV(CHAR_INFO *pBuf, int x, int y, int length, WCHAR code, WORD attr) {
		for (int i = 0; i < length; i++) {
			setCharacter(pBuf, x, y + i, code, attr);
		}
	}

	void drawTriangle(CHAR_INFO *pBuf, int x, int y, int height, WCHAR code, WORD attr) {
		for (int i = 0; i < height; i++) {
			int a = height - 1;

			for (int j = height + i; j > 0; j--) {
				if (j - 1 <= i * 2) {
					int _x = x + a;

					if (_x > 79) _x = 79;

					int _y = y + i;

					if (_y > 24) _y = 24;

					setCharacter(pBuf, _x, _y, code, attr);
				}
				a--;
			}
		}
	}

	int doTokenize(char *szBuf, char szBufToken[8][MAX_TOKEN_SIZE]) {
		char *szpTemp;
		char *pNextToken = NULL;
		const char *pzDelimiter = " ";
		int _nTokenIndex = 0;

		szpTemp = strtok_s(szBuf, pzDelimiter, &pNextToken);

		while (szpTemp) {
			strcpy_s(szBufToken[_nTokenIndex++], sizeof(szBufToken[_nTokenIndex]), szpTemp);
			szpTemp = strtok_s(NULL, pzDelimiter, &pNextToken);
		}
		//if (atoi(szBufToken[1]) < 0) {
		//	strcpy_s(szBufToken[1], 16, "79");
		//	g_cdCurrentCursorPos.X = 79;
		//}
		//if (atoi(szBufToken[1]) > 79) {
		//	strcpy_s(szBufToken[1], 16, "0");
		//	g_cdCurrentCursorPos.X = 0;
		//}
		//if (atoi(szBufToken[2]) < 0) {
		//	strcpy_s(szBufToken[2], 16, "24");
		//	g_cdCurrentCursorPos.Y = 24;
		//}
		//if (atoi(szBufToken[2]) > 24) {
		//	strcpy_s(szBufToken[2], 16, "0");
		//	g_cdCurrentCursorPos.Y = 0;
		//}

		/*printf("ÅäÅ« ¼ö : %d\n", _nTokenIndex);

		for (int i = 0; i < _nTokenIndex; i++) {
		printf("%s\n", szBufToken[i]);
		}*/
		return _nTokenIndex;
	}

	int loadBinary(CHAR_INFO *pBuf, const char *szFileName) {
		FILE *fp;
		fopen_s(&fp, szFileName, "r");
		if (fp) {
			fread_s(pBuf, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), sizeof(CHAR_INFO), 2000, fp);
			fclose(fp);
		}

		return 1;
	}

	int saveBinary(CHAR_INFO *pBuf, const char *szFileName) {
		FILE *fp;
		fopen_s(&fp, szFileName, "w");
		fwrite(pBuf, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), 1, fp);
		fclose(fp);

		return 1;
	}

	void putSprite(int posx, int posy, int srcw, int srch, CHAR_INFO *pDest, CHAR_INFO *pSrc) {
		int src_buf_size = srcw * srch;
		int nStep = 0;
		int _i = 0;
		for (int i = 0; i < src_buf_size; i++) {
			nStep = i / srcw;
			pDest[_i + (nStep * SCREEN_WIDTH) + (posy * SCREEN_WIDTH) + posx] = pSrc[i];
			_i++;
			_i %= srcw;
		}
	}

	void startTGE(HANDLE *phStdout) {

		*phStdout = GetStdHandle(STD_OUTPUT_HANDLE);

		TGE::clearScreenBuffer(g_chiBuffer, 0x20, 0x0090);

		hThread_ReadInput = CreateThread(
			NULL, 0, input::MyThreadFunction, NULL, 0, &dwThreadId_ReadInput
		);
	}
	
	void endTGE() {

	}

	namespace input {
		char g_KeyTable[1024];
		DWORD _oldInputMode;
		HANDLE hStdin;
		COORD g_cdMousePos;

		DWORD WINAPI MyThreadFunction(LPVOID lpParam)
		{
			hStdin = GetStdHandle(STD_INPUT_HANDLE);
			DWORD _NumRead;
			INPUT_RECORD irInBuf[128];

			GetConsoleMode(hStdin, &_oldInputMode);
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

			while (1) {
				ReadConsoleInput(hStdin, irInBuf, 128, &_NumRead);
				for (DWORD i = 0; i < _NumRead; i++) {
					if (irInBuf[i].EventType == KEY_EVENT) {
						if (irInBuf[i].Event.KeyEvent.bKeyDown) {
							g_KeyTable[irInBuf[i].Event.KeyEvent.wVirtualKeyCode] = 1;
						}
						else {
							g_KeyTable[irInBuf[i].Event.KeyEvent.wVirtualKeyCode] = 0;
						}
					}
					else if (irInBuf[i].EventType == MOUSE_EVENT) {

						g_cdMousePos = {
							irInBuf[i].Event.MouseEvent.dwMousePosition.X,
							irInBuf[i].Event.MouseEvent.dwMousePosition.Y
						};
					}
				}
				Sleep(1);
			}
			SetConsoleMode(hStdin, _oldInputMode);
			return 0;
		}

		void setEditMode()
		{
			SetConsoleMode(hStdin, _oldInputMode);
		}
		void setNormalMode()
		{
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
		}

	}

	namespace util {

		UINT64 GetTimeMs64()
		{
			FILETIME ft;
			LARGE_INTEGER li;

			GetSystemTimeAsFileTime(&ft);
			li.LowPart = ft.dwLowDateTime;
			li.HighPart = ft.dwHighDateTime;

			UINT64 ret_value = li.QuadPart;
			ret_value -= 116444736000000000LL;
			ret_value /= 10000;

			return ret_value;

		}
	}
}