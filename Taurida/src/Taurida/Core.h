#pragma once

#ifdef TRD_PLATFORM_WINDOWS
	#ifdef TRD_BUILD_DLL
		#define TAURIDA_API __declspec(dllexport)
	#else 
		#define TAURIDA_API __declspec(dllimport)
	#endif
#else
	#error Taurida only supports Windows!
#endif

#ifdef TRD_ENABLE_ASSERTS
	#define TRD_ASSERT(x, ...) { if(!(x)) { TRD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TRD_CORE_ASSERT(x, ...) { if(!(x)) { TRD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TRD_ASSERT(x, ...)
	#define TRD_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)