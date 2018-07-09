#include "stdafx.h"

int main() {
	HANDLE hdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD fdwSaveOldMode, cNumRead, fdwMode;
	INPUT_RECORD irlnBuf[128];

	GetConsoleMode(hdin, &fdwSaveOldMode); // �⺻ �ָܼ�带 ����
	// ���콺��� ����
	fdwMode = ENABLE_EXTENDED_FLAGS;
	SetConsoleMode(hdin, fdwMode); // �����͸�� ��Ȱ��ȭ
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; // ���콺��� Ȱ��ȭ
	SetConsoleMode(hdin, fdwMode);

	while (1) {
		ReadConsoleInput(hdin, irlnBuf, sizeof(irlnBuf)/sizeof(INPUT_RECORD), &cNumRead);

		for (int i = 0; i < cNumRead; i++) {
			switch (irlnBuf[i].EventType)
			{
			case KEY_EVENT:
				if (irlnBuf->Event.KeyEvent.bKeyDown) {
					printf("key pressed %d\n", irlnBuf[i].Event.KeyEvent.wVirtualKeyCode);
				}
				else {
					if (irlnBuf[i].Event.KeyEvent.wVirtualKeyCode == 81) return 0;

					printf("key released %d\n", irlnBuf[i].Event.KeyEvent.wVirtualKeyCode);
				}
				
				break;
			case MOUSE_EVENT:
				if (irlnBuf[i].Event.MouseEvent.dwButtonState == 1) {
					printf("%d %d\n", irlnBuf[i].Event.MouseEvent.dwMousePosition.X, irlnBuf[i].Event.MouseEvent.dwMousePosition.Y);
				}
				
				break;
			default:
				printf("event type : %d\n", irlnBuf[i].EventType);
				break;
			}
			
		}
	}
	SetConsoleMode(hdin, fdwSaveOldMode);

	return 0;
}