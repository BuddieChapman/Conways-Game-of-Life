#pragma once
#include <vector>
#include <SDL.h>

namespace sdl
{
	// defined in sdl-event-observer.h
	class EventObserver;

	class EventObservable
	{
	private:
		SDL_Event event;
		std::vector<sdl::EventObserver*> observers;
	public:
		void subscribe(sdl::EventObserver& observer);
		void unsubscibe(sdl::EventObserver& observer);
		void pollEvents();
	};
}