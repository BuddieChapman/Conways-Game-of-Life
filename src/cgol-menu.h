#pragma once
#include "sdl-event-observer.h"
#include <SDL.h>
#include <SDL_ttf.h>

namespace cgol
{
	class Menu : public sdl::EventObserver
	{
	private:
		bool quit;
		SDL_Texture* buttonText;
		SDL_Texture* menuText;
		SDL_Rect buttonRect;
		SDL_Rect menuRect;
		bool menuOpen;
	public:
		Menu(SDL_Renderer* renderer, TTF_Font* font);
		~Menu();
		bool hasQuit() const;
		void handleEvent(const SDL_Event& event);
		void render(SDL_Renderer* renderer);
	};
}