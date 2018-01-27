#pragma once
#include <SDL2/SDL_events.h>
#include <functional>
#include <iostream>
#include <vector>

struct Key {
	SDL_EventType type;
	std::function<void()> event;
	std::string eventName;
};
//Dispatches and qeues input
//Aliases Keys so one can rebind
class InputManager {
public:
	bool DoInput();		//If DoInput returns false it should quit
	void RegisterInput(Key&);
private:
	std::vector<Key> EventDispatcher;
};
