#pragma once
#include <SDL.h>

namespace sdl
{
	class EventObserver
	{
	public:
		virtual void handleEvent(SDL_Event& event) = 0;
	};
}