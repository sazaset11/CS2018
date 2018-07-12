#include "stdafx.h"
#include "../../engine/TGE.h"
#include "../../engine/maptool_struct.h"
using namespace tge;

enum { MODE_BRUSH_DRAW = 0, MODE_CMD_INPUT = 1, MODE_BRUSH_MOVE = 2, MODE_MOUSE_DRAW = 3 };

int main() {
	HANDLE hdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD fdwOldMode;
	S_TGE_MAPTOOL g_MapToolObject;
	static char szCmdBuf[32];
	int FSM = MODE_BRUSH_MOVE;
	static DWORD cNumRead;
	static INPUT_RECORD irInputBuf[128];
	int size_x = 1;
	int size_y = 1;

	GetConsoleMode(hdin, &fdwOldMode);
	SetConsoleMode(hdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	initMapTool(&g_MapToolObject);
	clearScreenBuffer(0x2e, 0x0007);

	while (1) {
		updateBuffer(hdout, g_chiBuffer);
		setCursor(hdout, 0, 0);
		setCursor(hdout, 0, 25);
		switch (FSM)
		{
		case MODE_BRUSH_DRAW:
			//비동기 키입력 처리
		{
			printf("							");
			setCursor(hdout, 0, 26);
			ReadConsoleInput(hdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0; i < cNumRead; i++) {
				if (irInputBuf[i].EventType == KEY_EVENT) {
					if (irInputBuf[i].Event.KeyEvent.bKeyDown) {
						printf("%d", irInputBuf[i].Event.KeyEvent.wVirtualKeyCode);

						switch (irInputBuf[i].Event.KeyEvent.wVirtualKeyCode)
						{
						case 37:
							sprintf_s(szCmdBuf, 32, "box %d %d %d %d %x %x", --g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y, 
								g_MapToolObject.m_wCurrentCursorSizeX, g_MapToolObject.m_wCurrentCursorSizeY, g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							//g_MapToolObject.m_cdCurrentCursorPos.X -= 1;
							break;
						case 38:
							sprintf_s(szCmdBuf, 32, "box %d %d %d %d %x %x", g_MapToolObject.m_cdCurrentCursorPos.X, --g_MapToolObject.m_cdCurrentCursorPos.Y, 
								g_MapToolObject.m_wCurrentCursorSizeX, g_MapToolObject.m_wCurrentCursorSizeY, g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							//g_MapToolObject.m_cdCurrentCursorPos.Y -= 1;
							break;
						case 39:
							sprintf_s(szCmdBuf, 32, "box %d %d %d %d %x %x", ++g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y, 
								g_MapToolObject.m_wCurrentCursorSizeX, g_MapToolObject.m_wCurrentCursorSizeY, g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							//g_MapToolObject.m_cdCurrentCursorPos.X += 1;
							break;
						case 40:
							sprintf_s(szCmdBuf, 32, "box %d %d %d %d %x %x", g_MapToolObject.m_cdCurrentCursorPos.X, ++g_MapToolObject.m_cdCurrentCursorPos.Y, 
								g_MapToolObject.m_wCurrentCursorSizeX, g_MapToolObject.m_wCurrentCursorSizeY, g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							//g_MapToolObject.m_cdCurrentCursorPos.Y += 1;
							break;
						case 68:
							SetConsoleMode(hdin, fdwOldMode);
							FSM = MODE_BRUSH_MOVE;
							break;
						case 107:
							if (g_MapToolObject.m_wCurrentCursorSizeX < 3) {
								g_MapToolObject.m_wCurrentCursorSizeX++;
								g_MapToolObject.m_wCurrentCursorSizeY++;
							}

							break;
						case 109:
							if (g_MapToolObject.m_wCurrentCursorSizeX > 1) {
								g_MapToolObject.m_wCurrentCursorSizeX--;
								g_MapToolObject.m_wCurrentCursorSizeY--;
							}

							break;
						default:
							break;
						}
					}
				}
			}

		}
		break;
		case MODE_CMD_INPUT:
			//스크립트 입력처리
			printf("						]");
			setCursor(hdout, 0, 25);
			printf("[cmd > ");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			//SetConsoleMode(hdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
			FSM = MODE_BRUSH_MOVE;

			break;
		case MODE_BRUSH_MOVE:
			printf("							");
			setCursor(hdout, 0, 26);
			ReadConsoleInput(hdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0; i < cNumRead; i++) {
				if (irInputBuf[i].EventType == KEY_EVENT) {
					if (irInputBuf[i].Event.KeyEvent.bKeyDown) {
						printf("%d", irInputBuf[i].Event.KeyEvent.wVirtualKeyCode);

						switch (irInputBuf[i].Event.KeyEvent.wVirtualKeyCode)
						{
						case 13:
							SetConsoleMode(hdin, fdwOldMode);
							FSM = MODE_CMD_INPUT;
							break;
						case 37:
							sprintf_s(szCmdBuf, 32, "cursor %d %d %4x %4x", 
								--g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y, g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							//g_MapToolObject.m_cdCurrentCursorPos.X -= 1;
							break;
						case 38:
							sprintf_s(szCmdBuf, 32, "cursor %d %d %4x %4x", 
								g_MapToolObject.m_cdCurrentCursorPos.X, --g_MapToolObject.m_cdCurrentCursorPos.Y, g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							//g_MapToolObject.m_cdCurrentCursorPos.Y -= 1;
							break;
						case 39:
							sprintf_s(szCmdBuf, 32, "cursor %d %d %4x %4x", 
								++g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y, g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							//g_MapToolObject.m_cdCurrentCursorPos.X += 1;
							break;
						case 40:
							sprintf_s(szCmdBuf, 32, "cursor %d %d %4x %4x", 
								g_MapToolObject.m_cdCurrentCursorPos.X, ++g_MapToolObject.m_cdCurrentCursorPos.Y, g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							//g_MapToolObject.m_cdCurrentCursorPos.Y += 1;
							break;
						case 68:
							SetConsoleMode(hdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
							strcpy_s(szCmdBuf, sizeof(szCmdBuf), "cursorend");
							FSM = MODE_BRUSH_DRAW;
							break;
						case 77:
							SetConsoleMode(hdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
							FSM = MODE_MOUSE_DRAW;
							break;
						case 107:
							if (g_MapToolObject.m_wCurrentCursorSizeX < 3) {
								g_MapToolObject.m_wCurrentCursorSizeX++;
								g_MapToolObject.m_wCurrentCursorSizeY++;
							}

							break;
						case 109:
							if (g_MapToolObject.m_wCurrentCursorSizeX > 1) {
								g_MapToolObject.m_wCurrentCursorSizeX--;
								g_MapToolObject.m_wCurrentCursorSizeY--;
							}

							break;
						default:
							break;
						}
					}
				}
			}

			break;
		case MODE_MOUSE_DRAW:
			printf("							");
			setCursor(hdout, 0, 26);
			ReadConsoleInput(hdin, irInputBuf, 128, &cNumRead);
			for (DWORD i = 0; i < cNumRead; i++) {
				if (irInputBuf[i].EventType == MOUSE_EVENT) {
					printf("%d", irInputBuf[i].Event.KeyEvent.wVirtualKeyCode);

					if (irInputBuf[i].Event.MouseEvent.dwButtonState == 1) {
						g_MapToolObject.m_cdCurrentCursorPos.X = irInputBuf[i].Event.MouseEvent.dwMousePosition.X;
						g_MapToolObject.m_cdCurrentCursorPos.Y = irInputBuf[i].Event.MouseEvent.dwMousePosition.Y;
						sprintf_s(szCmdBuf, 32, "box %d %d %d %d %x %x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
							g_MapToolObject.m_wCurrentCursorSizeX, g_MapToolObject.m_wCurrentCursorSizeY, g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
					}
					else if (irInputBuf[i].Event.MouseEvent.dwButtonState == 2) {
						//strcpy_s(szCmdBuf, sizeof(szCmdBuf), "cursorend");
						SetConsoleMode(hdin, fdwOldMode);
						FSM = MODE_BRUSH_MOVE;
						break;
					}
				}
			}

			break;
		default:
			break;
		}

		if (!parseCmd(&g_MapToolObject, szCmdBuf)) return 0;
	}

	return 0;
}