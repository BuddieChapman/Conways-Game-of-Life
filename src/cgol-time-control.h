#pragma once
#include "sdl-event-observer.h"
#include "cgol-grid.h"
#include <SDL.h>
#include <SDL_ttf.h>

namespace cgol
{
	class TimeControl : public sdl::EventObserver
	{
	private:
		Uint32 lastTick;
		Uint32 tickRate;
		bool paused;
		const int RATE_SLOW = 250;
		const int RATE_MEDIUM = 100;
		const int RATE_FAST = 30;
		SDL_Texture* pausedText;
		SDL_Rect textRect;
	public:
		TimeControl(SDL_Renderer* renderer, TTF_Font* font);
		virtual void handleEvent(const SDL_Event& event);
		void update(cgol::Grid& grid);
		void render(SDL_Renderer* renderer);
	};
}