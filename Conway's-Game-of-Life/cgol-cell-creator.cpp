#pragma once
#include "cgol-cell-creator.h"
#include "sdl-cell-rect.h"
#include <math.h>

cgol::CellCreator::CellCreator(cgol::Grid& grid, const SDL_Rect& camera)
{
	this->grid = &grid;
	this->camera = &camera;
}

void cgol::CellCreator::handleEvent(const SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT)
	{
		float clickX = event.button.x + camera->x;
		float clickY = event.button.y + camera->y;
		int gridColumn = floor(clickX / sdl::CellRect::CELL_WIDTH);
		int gridRow = floor(clickY / sdl::CellRect::CELL_HEIGHT);

		if (grid->isAlive({ gridColumn, gridRow }))
		{
			grid->setDead({ gridColumn, gridRow });
		}
		else
		{
			grid->setAlive({ gridColumn, gridRow });
		}
	}
	else if (event.type == SDL_MOUSEMOTION && SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LCTRL])
	{
		float mouseX = event.motion.x + camera->x;
		float mouseY = event.motion.y + camera->y;
		int gridColumn = floor(mouseX / sdl::CellRect::CELL_WIDTH);
		int gridRow = floor(mouseY / sdl::CellRect::CELL_HEIGHT);

		grid->setAlive({ gridColumn, gridRow });
	}
}