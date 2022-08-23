#pragma once

#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define RANGER_API __declspec(dllexport)
	#else
		#define RANGER_API __declspec(dllimport)
	#endif
#endif