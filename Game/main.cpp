#include "engine.h"
#include "window.h"
#include "draw.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, int)
{
	int w = GetSystemMetrics(SM_CXSCREEN);
	int h = GetSystemMetrics(SM_CYSCREEN);

	HWND hwnd = InitWindow(hInstance, w, h);
	PrepareScreen(hwnd, w, h);

	RunMessageLoop();
	return 0;
}