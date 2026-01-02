#pragma once
#include <windows.h>

class Draw
{
public:

	LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void MakeBitMap(HWND hwnd, HBITMAP* Bitmap, BITMAPINFO Bmi, DWORD** window_p, int Width, int Height);

	void Prepare_Screen(HWND hwnd);

	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow);

	void draw();
};
