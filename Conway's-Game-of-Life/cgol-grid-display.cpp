#include "cgol-grid-display.h"
#include "sdl-cell-rect.h"

cgol::GridDisplay::GridDisplay(cgol::Grid& grid)
{
	this->grid = &grid;
	mouseDown = false;
	camera.x = camera.y = 0;
}

void cgol::GridDisplay::render(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	for (auto cell : grid->getLivingCells())
	{
		SDL_Rect cellRect = sdl::CellRect(cell).getRect();
		cellRect.x -= camera.x;
		cellRect.y -= camera.y;
		SDL_RenderFillRect(renderer, &cellRect);
	}
}

void cgol::GridDisplay::handleEvent(SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
	{
		mouseDown = true;
	}
	else if (event.type == SDL_MOUSEBUTTONUP)
	{
		mouseDown = false;
	}
	else if (event.type == SDL_MOUSEMOTION)
	{
		if (mouseDown)
		{
			camera.x -= event.motion.xrel;
			camera.y -= event.motion.yrel;
		}
	}
}

const SDL_Rect& cgol::GridDisplay::getCamera() const
{
	return camera;
}