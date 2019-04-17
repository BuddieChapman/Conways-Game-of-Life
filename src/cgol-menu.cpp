#include "cgol-menu.h"
#include <iostream>

cgol::Menu::Menu(SDL_Renderer* renderer, TTF_Font* font)
{
	quit = false;
	menuOpen = false;
	auto controlsStr = "Right Click - Toggle Cell\n"
		"Left Click - Scroll\n"
		"Left Control (hold) - Create cell under mouse\n"
		"Mouse Wheel - zoom\n"
		"Spacebar - Pause / Unpause\n"
		"Right Arrow - Speed Up\n"
		"Left Arrow - Slow Down\n\n"
		"Escape - Toggle Menu";

	if (font)
	{
		SDL_Surface* temp = TTF_RenderText_Blended_Wrapped(font, "MENU", { 255, 255, 255, 255 }, 100);
		buttonText = SDL_CreateTextureFromSurface(renderer, temp);
		SDL_FreeSurface(temp);
		SDL_QueryTexture(buttonText, NULL, NULL, &buttonRect.w, &buttonRect.h);

		temp = TTF_RenderText_Blended_Wrapped(font, controlsStr, { 255,255,255,255 }, 400);
		menuText = SDL_CreateTextureFromSurface(renderer, temp);
		SDL_FreeSurface(temp);
		SDL_QueryTexture(menuText, NULL, NULL, &menuRect.w, &menuRect.h);
	}
}

cgol::Menu::~Menu()
{
	SDL_DestroyTexture(buttonText);
	SDL_DestroyTexture(menuText);
}

bool cgol::Menu::hasQuit() const
{
	return quit;
}

void cgol::Menu::handleEvent(const SDL_Event& event)
{
	if (event.type == SDL_QUIT)
	{
		quit = true;
	}
	else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
	{
		menuOpen = !menuOpen;
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
	{
		SDL_Point clickPos = { event.button.x, event.button.y };
		//std::cout << clickPos.x << clickPos
		if (SDL_PointInRect(&clickPos, &buttonRect))
		{
			menuOpen = true;
		}
	}
}

void cgol::Menu::render(SDL_Renderer* renderer)
{
	const auto BUFFER = 10;
	int screenWidth, screenHeight;
	SDL_GetRendererOutputSize(renderer, &screenWidth, &screenHeight);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	if (menuOpen)
	{
		menuRect.x = (screenWidth - menuRect.w) / 2;
		menuRect.y = (screenHeight - menuRect.h) / 2;
		SDL_RenderFillRect(renderer, &menuRect);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawRect(renderer, &menuRect);
		SDL_RenderCopy(renderer, menuText, NULL, &menuRect);
	}
	else
	{
		buttonRect.x = screenWidth - buttonRect.w - BUFFER;
		buttonRect.y = screenHeight - buttonRect.h - BUFFER;
		SDL_RenderFillRect(renderer, &buttonRect);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderCopy(renderer, buttonText, NULL, &buttonRect);
		SDL_RenderDrawRect(renderer, &buttonRect);
	}
}