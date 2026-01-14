#include "engine.h"
#include "window.h"
#include "draw.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, int)
{
	Engine e;
	int w = GetSystemMetrics(SM_CXSCREEN);
	int h = GetSystemMetrics(SM_CYSCREEN);

	HWND hwnd = InitWindow(hInstance, w, h);
	prepare_screen(hwnd, w, h);

	e.game_start();

	MSG msg = { 0 };

	while(true)
	{
		while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return 0;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		e.game_loop(hwnd);
	}

	return 0;
}