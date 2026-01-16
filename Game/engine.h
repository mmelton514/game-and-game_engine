#pragma once
#include <windows.h>

class Engine
{
public:

	void game_start() const;

	int game_loop(HWND hwnd);

private :

	void engine_update() const;

	void engine_draw(HWND hwnd) const;
};
