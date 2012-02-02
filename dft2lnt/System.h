#ifndef SYSTEM_H
#define SYSTEM_H

#define SYSTEM_TIMER_BACKEND_MONOTONIC     1
#define SYSTEM_TIMER_BACKEND_MONOTONIC_RAW 2
#define SYSTEM_TIMER_BACKEND_WINDOWS       3

#include <time.h>
#ifdef WIN32
#	include <windows.h>
#	define SYSTEM_TIMER_BACKEND SYSTEM_TIMER_BACKEND_WINDOWS
#else
#	define SYSTEM_TIMER_BACKEND SYSTEM_TIMER_BACKEND_MONOTONIC_RAW
#endif

class System {
public:
	class Timer {
	private:
	#if SYSTEM_TIMER_BACKEND == SYSTEM_TIMER_BACKEND_WINDOWS
		LARGE_INTEGER freq;
		LARGE_INTEGER start;
	#endif
	#if SYSTEM_TIMER_BACKEND == SYSTEM_TIMER_BACKEND_MONOTONIC_RAW
		timespec start;
	#endif
	public:
		Timer();
		Timer* create();
		void reset();
		double getElapsedSeconds();
	};

	static void sleep(uint64_t ms);
};

#endif
