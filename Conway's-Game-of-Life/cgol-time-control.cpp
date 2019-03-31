#include "cgol-time-control.h"
#include <SDL.h>

cgol::TimeControl::TimeControl()
{
	paused = false;
	tickRate = RATE_MEDIUM;
	lastTick = 0;
}

void cgol::TimeControl::handleEvent(const SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		auto keyPressed = event.key.keysym.sym;
		if(keyPressed == SDLK_SPACE) 
		{
			paused = !paused;
		}
		else if (keyPressed == SDLK_RIGHT)
		{
			if (tickRate == RATE_SLOW)
			{
				tickRate = RATE_MEDIUM;
			}
			else if (tickRate == RATE_MEDIUM)
			{
				tickRate = RATE_FAST;
			}
		}
		else if(keyPressed == SDLK_LEFT)
		{
			if (tickRate == RATE_FAST)
			{
				tickRate = RATE_MEDIUM;
			}
			else if (tickRate == RATE_MEDIUM)
			{
				tickRate = RATE_SLOW;
			}
		}
	}
}

void cgol::TimeControl::update(cgol::Grid& grid)
{
	if (!paused && lastTick + tickRate < SDL_GetTicks())
	{
		lastTick = SDL_GetTicks();
		grid.update();
	}
}