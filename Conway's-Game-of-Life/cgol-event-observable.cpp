#include "sdl-event-observable.h"
#include "sdl-event-observer.h"

void sdl::EventObservable::subscribe(sdl::EventObserver& observer)
{
	observers.push_back(&observer);
}

void sdl::EventObservable::unsubscibe(sdl::EventObserver& observer)
{
	for (auto it = observers.begin(); it != observers.end(); ++it)
	{
		if (*it == &observer)
		{
			observers.erase(it);
			break;
		}
	}
}

void sdl::EventObservable::pollEvents()
{
	while (SDL_PollEvent(&event))
	{
		for (auto observer : observers)
		{
			observer->handleEvent(event);
		}
	}
}