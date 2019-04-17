#include "cgol-grid-display.h"
#include "sdl-cell-rect.h"

cgol::GridDisplay::GridDisplay(cgol::Grid& grid)
{
	this->grid = &grid;
	mouseDown = false;
	camera.x = camera.y = 0;
	camera.zoom = 1;
}

void cgol::GridDisplay::render(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	for (auto cell : grid->getLivingCells())
	{
		SDL_Rect cellRect = sdl::CellRect(cell).getRect();
		cellRect.x -= camera.x;
		cellRect.y -= camera.y;
		cellRect.x *= camera.zoom;
		cellRect.y *= camera.zoom;
		cellRect.w *= camera.zoom;
		cellRect.h *= camera.zoom;
		SDL_RenderFillRect(renderer, &cellRect);
	}
}

void cgol::GridDisplay::handleEvent(const SDL_Event& event)
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
			camera.x -= event.motion.xrel / camera.zoom;
			camera.y -= event.motion.yrel / camera.zoom;
		}
	}
	else if (event.type == SDL_MOUSEWHEEL)
	{
		if (event.wheel.y > 0)
		{
			if (camera.zoom > 1)
			{
				++camera.zoom;
			}
			else
			{
				camera.zoom *= 2;
			}
		}
		else
		{
			if (camera.zoom > 1)
			{
				--camera.zoom;
			}
			else
			{
				if (sdl::CellRect::CELL_WIDTH * camera.zoom / 2 > 1)
				{
					camera.zoom /= 2;
				}
			}
		}
	}
}

const cgol::Camera& cgol::GridDisplay::getCamera() const
{
	return camera;
}