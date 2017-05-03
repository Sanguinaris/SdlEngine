#include <Windows.h>
#include "General/Engine.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int mCmdShow)
{
	Engine engine;
	if (!engine.Initialize())
		return 1;
	engine.Run();
	engine.Shutdown();
	return 0;
}
