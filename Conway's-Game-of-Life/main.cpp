#include <iostream>
#include "cgol-grid.h"
#include <SDL.h>
#include "sdl-cell-rect.h"

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer(500, 500, SDL_WINDOW_RESIZABLE, &window, &renderer);
	SDL_Event e;
	bool running = true;
	cgol::Grid grid;

	grid.setAlive({ 10, 10 });
	grid.setAlive({ 11, 10 });
	grid.setAlive({ 9, 10 });
	
	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) running = false;
		}
		grid.update();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		for (auto cell : grid.getLivingCells())
		{
			sdl::CellRect cellRect(cell);
			SDL_RenderFillRect(renderer, &cellRect.getRect());
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(100);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}