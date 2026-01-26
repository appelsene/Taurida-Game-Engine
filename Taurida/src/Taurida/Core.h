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

#define BIT(x) (1 << x)