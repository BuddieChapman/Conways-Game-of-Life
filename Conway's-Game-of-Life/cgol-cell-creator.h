#pragma once
#include "sdl-event-observer.h"
#include "cgol-grid.h"

namespace cgol
{
	class CellCreator : public sdl::EventObserver
	{
	private:
		cgol::Grid* grid;
		const SDL_Rect* camera;
	public:
		CellCreator(cgol::Grid& grid, const SDL_Rect& camera);
		virtual void handleEvent(const SDL_Event& event);
	};
}
