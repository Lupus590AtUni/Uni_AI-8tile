#include "NA_Timer.h"
#include <time.h>


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
		//should probably tell the os that we are waiting
	}
}
