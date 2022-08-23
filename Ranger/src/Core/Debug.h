#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Debug
{
	//static std::shared_ptr<spdlog::logger> console;
	void Init()
	{
		spdlog::set_pattern("%^[%T] %v%$");
		//console = spdlog::stdout_color_mt("console");
	}

	void Log(const char* str)
	{
		spdlog::info(str);
	}

	template<typename... Args>
	void Log(const char* str, Args &&... args)
	{
		spdlog::info(str, std::forward<Args>(args)...);
	}

	void LogWarn(const char* str)
	{
		spdlog::warn(str);
	}

	template<typename... Args>
	void LogWarn(const char* str, Args &&... args)
	{
		spdlog::warn(str, std::forward<Args>(args)...);
	}

	void LogError(const char* str)
	{
		spdlog::error(str);
	}

	template<typename... Args>
	void LogError(const char* str, Args &&... args)
	{
		spdlog::error(str, std::forward<Args>(args)...);
	}
}

#define DEBUG_LOG(...) ::Debug::Log(__VA_ARGS__)
#define DEBUG_WARN(...) ::Debug::LogWarn(__VA_ARGS__)
#define DEBUG_ERROR(...) ::Debug::LogError(__VA_ARGS__)