#include "NA_MathsLib.h"
#include <math.h>//used to generate lookup tables when object is constructed
#include <random>
#include <time.h>

const float NA_MathsLib::PI = 3.14f;//this is a stupid compiler rule in my opinion

NA_MathsLib maths; //contructs itself, access with extern NA_MathsLib maths;

NA_MathsLib::NA_MathsLib(void)
{

  for(int i=0; i<NA_M_LOOKUP_MAX; i++)//walk through lookup table assigning values from math.h
  {
    sinLookup[(int)i] = (float) sinf(degToRad((float)i*NA_M_LOOKUP_UNIT));
    cosLookup[(int)i] = (float) cosf(degToRad((float)i*NA_M_LOOKUP_UNIT));
    tanLookup[(int)i] = (float) tanf(degToRad((float)i*NA_M_LOOKUP_UNIT));
  }

}

NA_MathsLib::~NA_MathsLib(void)
{
}

#pragma region dice



void NA_MathsLib::seedDice(unsigned int seed)
{
	srand(seed);
}

int NA_MathsLib::dice(int bottom, int top)
{
	//https://answers.yahoo.com/question/index?qid=20100615173601AAMHzBy
	return (rand() % ((top + 1) - bottom)) + bottom;//between bottom and top, inclusive
}

int NA_MathsLib::dice(int top)
{
	return (rand() % (top+1)); //between 0 and top, inclusive
}

#pragma endregion

#pragma region trig

float NA_MathsLib::degToRad(float d)
{
	return (PI*d)/180;
}

float NA_MathsLib::radToDeg(float r)
{
	return (r*180)/PI;
}

int NA_MathsLib::degToLookupIndex(float d)
{
	return (int) d*(NA_M_LOOKUP_UNIT);
}

float NA_MathsLib::sin(float d)
{
	return sinLookup[degToLookupIndex(d)];
}
float NA_MathsLib::cos(float d)
{
	return cosLookup[degToLookupIndex(d)];
}
float NA_MathsLib::tan(float d)
{
	return tanLookup[degToLookupIndex(d)];
}

#pragma endregion

//returns true if the two floats are within 0.001 of each other
bool NA_MathsLib::aboutEqual(float v1, float v2, float epsilon)
{
	if (v1 > v2)
	{
		if( v1 - v2 < epsilon) return true;
	}
	else
	{
		if( v2 - v1 < epsilon) return true; //this returns true if they are exactly equal too, therefore a if(v1 == v2) statement is not required
	}
	return false; //if this line is executed then the two values are not similar enough to be considered the same
}