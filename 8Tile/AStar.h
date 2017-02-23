#pragma once
#include "EightTile.h"
extern EightTile myPuzzle;
class AStar
{
public:
	AStar();
	~AStar();
	int calcMissplaceCount(int** compare = myPuzzle.getTilesCopy());
	void solve();
};

