#include "sdl-cell-rect.h"

sdl::CellRect::CellRect(cgol::Cell cell)
{
	rect.x = cell.column * CELL_WIDTH;
	rect.y = cell.row * CELL_HEIGHT;
	rect.w = CELL_WIDTH;
	rect.h = CELL_HEIGHT;
}

const SDL_Rect& sdl::CellRect::getRect()
{
	return rect;
}