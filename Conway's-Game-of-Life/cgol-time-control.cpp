#include "cgol-time-control.h"
#include <SDL.h>

cgol::TimeControl::TimeControl()
{
	paused = false;
	tickRate = 100;
	lastTick = 0;
}

void cgol::TimeControl::handleEvent(const SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_SPACE: paused = !paused; break;
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