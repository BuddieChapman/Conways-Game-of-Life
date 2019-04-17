#pragma once
#include "sdl-event-observer.h"
#include "cgol-grid.h"
#include "cgol-grid-display.h"

namespace cgol
{
	class CellCreator : public sdl::EventObserver
	{
	private:
		cgol::Grid* grid;
		const cgol::Camera* camera;
	public:
		CellCreator(cgol::Grid& grid, const cgol::Camera& camera);
		virtual void handleEvent(const SDL_Event& event);
	};
}
