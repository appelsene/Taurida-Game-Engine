#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Taurida {

	class TAURIDA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define TRD_CORE_TRACE(...)     ::Taurida::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TRD_CORE_INFO(...)      ::Taurida::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TRD_CORE_WARN(...)      ::Taurida::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TRD_CORE_ERROR(...)     ::Taurida::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TRD_CORE_FATAL(...)     ::Taurida::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TRD_TRACE(...)          ::Taurida::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TRD_INFO(...)           ::Taurida::Log::GetClientLogger()->info(__VA_ARGS__)
#define TRD_WARN(...)           ::Taurida::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TRD_ERROR(...)          ::Taurida::Log::GetClientLogger()->error(__VA_ARGS__)
#define TRD_FATAL(...)          ::Taurida::Log::GetClientLogger()->fatal(__VA_ARGS__)