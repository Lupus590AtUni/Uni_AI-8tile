#include "AStar.h"



AStar::AStar()
{
}


AStar::~AStar()
{
}

int AStar::calcMissplaceCount(int ** compare)
{
	int missplacedCount = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (compare[i][j] != myPuzzle.getSolution(i, j))
			{
				missplacedCount++;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		delete compare[i];
	}
	delete compare;

	return missplacedCount;
}

void AStar::solve()
{
	// This reference gave me the general direction to go for making this function - https://www.cs.princeton.edu/courses/archive/spr10/cos226/assignments/8puzzle.html



}
