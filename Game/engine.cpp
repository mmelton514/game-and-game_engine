#include <iostream>
#include <array>

#include "draw.h"
#include "engine.h"

using namespace std;

int Engine::game_loop(HWND hwnd)
{
	engine_update();
	engine_draw(hwnd);
	return 0;
}

void Engine::engine_update()
{

}

void Engine::engine_draw(HWND hwnd)
{
	DrawFrame(hwnd);
}

void Engine::game_start()
{
	
}