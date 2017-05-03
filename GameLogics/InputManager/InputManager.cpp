#include "InputManager.h"

bool InputManager::DoInput()
{
	SDL_Event e;
	bool shouldExit = false;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			shouldExit = true;
	}
	return !shouldExit;
}

void InputManager::RegisterInput(Key &)
{
}
