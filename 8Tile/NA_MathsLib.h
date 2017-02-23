#pragma once
#include <time.h>

class NA_MathsLib
{
private:
	static const int NA_M_LOOKUP_MAX = 1024;
	static const int NA_M_LOOKUP_UNIT = 360/NA_M_LOOKUP_MAX;
	
	//could these be static?
	float sinLookup[(int)NA_M_LOOKUP_MAX];
	float cosLookup[(int)NA_M_LOOKUP_MAX];
	float tanLookup[(int)NA_M_LOOKUP_MAX];

	int degToLookupIndex(float);

public:
	void seedDice(unsigned int seed  = time(NULL));

	static const float PI;//floats must be initialised in cpp
	NA_MathsLib(void);
	~NA_MathsLib(void);

	//had to name dice as could not access randoms rand function if maths::rand was so named
	int dice(int bottom, int top);
	int dice(int top);

	float degToRad(float);
	float radToDeg(float);
	float sin(float);
	float cos(float);
	float tan(float);

	//returns true if the two floats are within 0.001 of each other
	bool aboutEqual(float v1, float v2, float epsilon = 0.001f);
};

