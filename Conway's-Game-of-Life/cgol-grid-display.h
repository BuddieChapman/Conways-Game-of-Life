#pragma once
#include <SDL.h>
#include "cgol-grid.h"
#include "sdl-event-observer.h"

namespace cgol
{
	struct Camera
	{
		float x, y;
		float zoom;
	};

	class GridDisplay : public sdl::EventObserver
	{
	private:
		cgol::Camera camera;
		cgol::Grid* grid;
		const SDL_Color cellColor = { 0, 0, 255, 255 };
		bool mouseDown;
	public:
		GridDisplay(cgol::Grid& grid);
		void render(SDL_Renderer* renderer) const;
		virtual void handleEvent(const SDL_Event& event);
		const cgol::Camera& getCamera() const;
	};
}