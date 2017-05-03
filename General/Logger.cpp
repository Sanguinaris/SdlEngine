#include "Logger.h"
#include <string>

Logger::Logger(std::string logFileName, char loggingFlag) : _logFlags(loggingFlag)
{
	logFile.open(logFileName, std::ios::ate);
}

Logger::~Logger()
{
	logFile.close();
}

void Logger::Log(std::string text, LoggingFlag type)
{
	if ((char)type & _logFlags)
	{
		logFile << " [" << (type == LoggingFlag::Information) ? "INFORMATION" : (type == LoggingFlag::Warning) ? "WARNING" : (type == LoggingFlag::Error) ? "ERROR" : " ";
		logFile << "] " << text << std::endl;
		logFile.flush();
	}
}
