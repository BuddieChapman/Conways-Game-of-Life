#pragma once
#include "sdl-event-observer.h"
#include "cgol-grid.h"

namespace cgol
{
	class TimeControl : public sdl::EventObserver
	{
	private:
		Uint32 lastTick;
		Uint32 tickRate;
		bool paused;
		const int RATE_SLOW = 250;
		const int RATE_MEDIUM = 100;
		const int RATE_FAST = 30;
	public:
		TimeControl();
		virtual void handleEvent(const SDL_Event& event);
		void update(cgol::Grid& grid);
	};
}