#include <iostream>
#include <array>

#include "draw.h"
#include "engine.h"

using namespace std;

int Engine::game_loop()
{
	update();
	draw();
	return 0;
}

void Engine::update()
{

}

void Engine::draw()
{
	
}

void Engine::game_start()
{
	game_loop();
}