#include "Log.h"

namespace Valk 
{
	std::shared_ptr<spdlog::logger> Log::coreLogger;

	void Log::Init() 
	{
		spdlog::set_pattern("[%H:%M:%S] [%n]: %v");
		coreLogger = spdlog::stdout_color_mt("VALK");
		coreLogger->set_level(spdlog::level::trace);
	}

	void Log::Print() 
	{
		std::cout << "WORKS!" << std::endl;
	}
}