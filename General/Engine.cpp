#include "Engine.h"

#include <thread>
#include <string>
#include <chrono>

using namespace std::chrono_literals;

bool Engine::InitEngine()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		logger.Log("Couldnt init SDL: " + std::string(SDL_GetError()), LoggingFlag::Error);
		return false;
	}

	if (TTF_Init() < 0)
	{
		logger.Log("Couldnt init ttf: " + std::string(SDL_GetError()), LoggingFlag::Error);
		return false;
	}

	Uint32 WindowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;
	if (optionMgr.bFullscreen)
		WindowFlags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

	window = SDL_CreateWindow(_GameName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, optionMgr.wRes, optionMgr.hRes, WindowFlags);
	
	if (!window)
	{
		logger.Log("Couldnt create Window: " + std::string(SDL_GetError()), LoggingFlag::Error);
		return false;
	}

	WindowFlags = SDL_RENDERER_ACCELERATED;
	if (optionMgr.bVSync)
		WindowFlags |= SDL_RENDERER_PRESENTVSYNC;
	renderer = SDL_CreateRenderer(window, -1, WindowFlags);

	if (!renderer)
	{
		logger.Log("Couldnt create Renderer: " + std::string(SDL_GetError()), LoggingFlag::Error);
		return false;
	}

	font = TTF_OpenFont("arial.ttf", 10);
	if (!font)
	{
		logger.Log("Couldnt create font: " + std::string(TTF_GetError()), LoggingFlag::Error);
		return false;
	}

	SDL_Surface* tempFontText = TTF_RenderText_Solid(font, "Hello World!", { 255,0,0,255 });
	if (!tempFontText)
	{
		logger.Log("Couldnt create font: " + std::string(TTF_GetError()), LoggingFlag::Error);
		return false;
	}

	fontTexture = SDL_CreateTextureFromSurface(renderer, tempFontText);
	SDL_FreeSurface(tempFontText);

	return true;
}

bool Engine::Initialize()
{
	optionMgr.Load();
	if (!InitEngine())
		return false;
	if (!mapMgr.Init())
		return false;
}

void Engine::Run()
{
	SDL_Rect dst;
	dst.x = 100;
	dst.y = 100;
	SDL_QueryTexture(fontTexture, NULL, NULL, &dst.w, &dst.h);
	while (true) {
		if (!inputMgr.DoInput())
			return;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderDrawLine(renderer, 10, 10, 100, 100);
		SDL_RenderCopy(renderer, fontTexture, NULL, &dst);
		SDL_RenderPresent(renderer);
	}
}

void Engine::RunAsync()	//SETS UP ALL MANAGERS TO run asynchronous (performance boost?)
{
	shouldRun = true;
	while (shouldRun)
	{
		isRunning = true;
	}
	isRunning = false;
}

void Engine::Shutdown()
{
	if (!mapMgr.Shutdown())
		logger.Log("Failed to shutdown the Mapmgr", LoggingFlag::Error);
	shouldRun = false;
	for (; isRunning; std::this_thread::sleep_for(100ms));


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
}

SDL_Window * Engine::getWindow()
{
	return window;
}

SDL_Renderer * Engine::getRenderer()
{
	return renderer;
}

Logger& Engine::getLogger()
{
	return logger;
}

OptionManager & Engine::getOptionMgr()
{
	return optionMgr;
}

InputManager & Engine::getInputMgr()
{
	return inputMgr;
}

