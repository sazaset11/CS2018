#pragma once

void setCursor(HANDLE, int, int);
void setCharacter(CHAR_INFO*, int, int, WCHAR, WCHAR);
void clearScreenBuffer(CHAR_INFO*);
void updateBuffer(HANDLE, CHAR_INFO*);
void drawBox(int, int, int, int, WCHAR);
void drawLine(int, int, int, WCHAR);
void drawTriagle(int, int, int, WCHAR);