#pragma once
#include "../Map/MapManager.h"
#include "Logger.h"
#include "OptionManager.h"
#include "../GameLogics/InputManager/InputManager.h"
#include <SDL.h>
#include <sdl_ttf.h>
#include <iostream>

//Starting up engine, runnign game loop
class Engine {
public:
	Engine(std::string GameName = "DefaultGame") : _GameName(GameName) {};

private:
	bool InitEngine();

public:
	bool Initialize();
	void Run();
	void RunAsync();
	void Shutdown(); //We are shutting down we dont care if it fails or nah

public:
	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();
	
	Logger& getLogger();
	OptionManager& getOptionMgr();
	InputManager& getInputMgr();
private:
	Logger logger;
	OptionManager optionMgr;
	InputManager inputMgr;

	std::string _GameName;
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;
	SDL_Texture* fontTexture;

	MapManager mapMgr;
	bool shouldRun, isRunning;
};