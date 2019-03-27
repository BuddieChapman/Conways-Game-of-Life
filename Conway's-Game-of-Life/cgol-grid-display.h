#pragma once
#include <SDL.h>
#include "cgol-grid.h"
#include "sdl-event-observer.h"

namespace cgol
{
	class GridDisplay : public sdl::EventObserver
	{
	private:
		SDL_Rect camera;
		cgol::Grid* grid;
		const SDL_Color cellColor = { 0, 0, 255, 255 };
		bool mouseDown;
	public:
		GridDisplay(cgol::Grid& grid);
		void render(SDL_Renderer* renderer) const;
		virtual void handleEvent(SDL_Event& event);
		const SDL_Rect& getCamera() const;
	};
}