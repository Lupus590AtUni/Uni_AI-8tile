#pragma once
#include "EightTile.h"
extern EightTile myPuzzle;
class HillClimb
{
public:
	HillClimb();
	~HillClimb();
	int calcMissplaceCount(int** compare = myPuzzle.getTilesCopy());
	void solve();
};

