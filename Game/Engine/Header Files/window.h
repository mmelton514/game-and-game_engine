#pragma once
#include <windows.h>

HWND InitWindow(HINSTANCE hInstance, int width, int height);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);