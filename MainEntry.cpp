#include "General/Engine.h"

int main(void)
{
	Engine engine;
	if (!engine.Initialize())
		return 1;
	engine.Run();
	engine.Shutdown();
	return 0;
}
