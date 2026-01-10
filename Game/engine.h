#pragma once
#include <windows.h>

class Engine
{
public:

	void game_start();

	int game_loop(HWND hwnd);

private :

	void engine_update();

	void engine_draw(HWND hwnd);
};
