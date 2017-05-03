#include "OptionManager.h"

bool OptionManager::Init()
{
	return false;
}

bool OptionManager::Save()
{
	return false;
}

void OptionManager::Load()
{
	LoadDefaults();
}

void OptionManager::LoadDefaults()
{
	wRes = 800;
	hRes = 600;
	bFullscreen = false;
	bVSync = false;
}

bool OptionManager::Shutdown()
{
	return false;
}
