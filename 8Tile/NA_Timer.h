#pragma once

class NA_Timer
{
//private:
public:
	double duration;
	unsigned int start;
public:
	explicit NA_Timer(double d = 0.0);
	~NA_Timer(void);
	void setDuration(double d);
	bool hasElapsed();
	void restart();
	void waitForElapse(); //pause until timer elapses
};

