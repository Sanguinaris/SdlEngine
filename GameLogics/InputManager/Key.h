#pragma once
#include <SDL_events.h>
#include <functional>
#include <iostream>

struct Key {
	SDL_EventType type;
	std::function<void()> event;
	std::string eventName;
};