#include "cgol-time-control.h"
#include <SDL.h>
#include <SDL_ttf.h>

cgol::TimeControl::TimeControl(SDL_Renderer* renderer, TTF_Font* font)
{
	paused = false;
	tickRate = RATE_MEDIUM;
	lastTick = 0;

	auto pausedString = "PAUSED";
	if (font != NULL) {
		SDL_Surface* temp = TTF_RenderText_Blended(font, pausedString, { 255, 255, 255, 255 });
		pausedText = SDL_CreateTextureFromSurface(renderer, temp);
		TTF_SizeText(font, pausedString, &textRect.w, &textRect.h);
		SDL_FreeSurface(temp);
	}
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

void cgol::TimeControl::render(SDL_Renderer* renderer)
{
	if (paused)
	{
		SDL_RenderCopy(renderer, pausedText, NULL, &textRect);
	}
}