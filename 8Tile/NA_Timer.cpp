
#include "NA_Timer.h"
#include <time.h>
#ifdef  _WIN32
//https://msdn.microsoft.com/en-us/library/windows/desktop/ms737629(v=vs.85).aspx
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#endif



NA_Timer::NA_Timer(double d)
{
	duration = d;
	start = time(NULL);
}

NA_Timer::~NA_Timer(void)
{
}

void NA_Timer::setDuration(double d)
{
	duration = d;
}

bool NA_Timer::hasElapsed()
{
	if(duration < difftime(time(NULL),start))
		return true;
	//else
	return false;
}

void NA_Timer::restart()
{
	start = time(NULL);
}

void NA_Timer::waitForElapse()
{
	while (!hasElapsed())
	{
		#ifdef  _WIN32
			Sleep(250*(duration - difftime(time(NULL), start))); //quarter of a second mulitplied by remianing duration (which is in seconds)
		#endif
	}
}
