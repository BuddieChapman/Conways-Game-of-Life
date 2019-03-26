#pragma once
#include "cgol-cell.h"
#include <SDL.h>

namespace sdl
{
	class CellRect
	{
	private:
		SDL_Rect rect;
	public:
		CellRect(cgol::Cell cell);
		const SDL_Rect& getRect();
		static const int CELL_WIDTH = 10;
		static const int CELL_HEIGHT = 10;
	};
}
