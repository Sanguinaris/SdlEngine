#pragma once
#include <fstream>
#include <iostream>

class OptionManager {
public:
	bool Init();	//Loads config magical/ly
	bool Save();
	
	void Load();
	void LoadDefaults();
	
	bool Shutdown(); //Saves Config
public:
	bool bFullscreen, bVSync;
	int wRes, hRes;
private:
	std::string optionsFileName;
};