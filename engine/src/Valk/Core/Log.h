#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Valk 
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }

		static void Print();
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
	};
}

#define VALK_CORE_TRACE(...)       Valk::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VALK_CORE_INFO(...)        Valk::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VALK_CORE_DEBUG(...)       Valk::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define VALK_CORE_WARN(...)        Valk::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VALK_CORE_ERROR(...)       Valk::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VALK_CORE_CRITICAL(...)    Valk::Log::GetCoreLogger()->critical(__VA_ARGS__)