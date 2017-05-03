#pragma once
//Logg all ur credz muhahaha
#include <iostream>
#include <fstream>

enum class LoggingFlag : char {
	Information = (1u << 0),
	Warning = (1u << 1),
	Error = (1u << 2),
	Text = (1u << 3)
};

class Logger {
public:
	Logger(std::string logFileName = "log.txt", char loggingFlag = (char)LoggingFlag::Warning | (char)LoggingFlag::Error);
	~Logger();
public:
	void Log(std::string text, LoggingFlag type);

private:
	std::ofstream logFile;
	char _logFlags;
};