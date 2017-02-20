#include "HillClimb.h"
#include "EightTile.h"

#include <math.h>
#include <algorithm>    // std::swap
using std::swap;
#include <iostream>

using std::cout;

extern EightTile myPuzzle;

HillClimb::HillClimb()
{
}


HillClimb::~HillClimb()
{
}

int HillClimb::calcMissplaceCount(int** compare)//Used for tracking our progress
{
	int missplacedCount = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (compare[i][j] != myPuzzle.getSolution(i,j))
			{
				missplacedCount++;
			}
		}
	}
	return missplacedCount;
}


void HillClimb::solve()
{
	//TODO: Find out why it doesn't solve - it doesn't move the pieces
	int** tiles = NULL;
	while (true)
	{
		tiles = myPuzzle.getTilesCopy();
		int currentMissplacedCount = calcMissplaceCount();
		cout << "HillClimb::solve - currentMissplacedCount: " << currentMissplacedCount;
		if (currentMissplacedCount == 0)
		{
			cout << "Solved\n";
			break;
		}

		//only consider valid swaps
		int missplaceCountIfMove = currentMissplacedCount;
		move bestMove = NONE;
		int x = myPuzzle.getX();
		int y = myPuzzle.getY();
		if (myPuzzle.okDown())
		{
			swap(tiles[x][y], tiles[x][y+1]);//swap it
			int result = calcMissplaceCount(tiles);
			if (result < currentMissplacedCount)//see if it's an improvment
			{
				missplaceCountIfMove = result;
				bestMove = DOWN;
			}
			swap(tiles[x][y], tiles[x][y + 1]);//swap back so that eighttile can do it
		}
		if (myPuzzle.okUp())
		{
			swap(tiles[x][y], tiles[x][y - 1]);
			int result = calcMissplaceCount(tiles);
			if (result < currentMissplacedCount)
			{
				missplaceCountIfMove = result;
				bestMove = UP;
			}
			swap(tiles[x][y], tiles[x][y - 1]);
		}
		if (myPuzzle.okLeft())
		{
			swap(tiles[x][y], tiles[x - 1][y]);
			int result = calcMissplaceCount(tiles);
			if (result < currentMissplacedCount)
			{
				missplaceCountIfMove = result;
				bestMove = LEFT;
			}
			swap(tiles[x][y], tiles[x - 1][y]);
		}
		if (myPuzzle.okRight())
		{
			swap(tiles[x][y], tiles[x + 1][y]);
			int result = calcMissplaceCount(tiles);
			if (result < currentMissplacedCount)
			{
				missplaceCountIfMove = result;
				bestMove = RIGHT;
			}
			swap(tiles[x][y], tiles[x + 1][y]);
		}
		if (missplaceCountIfMove > currentMissplacedCount)
		{
			//stuck, maybe try a random move?
			cout << "Stuck\n";
			break;
		}
		myPuzzle.display();
		cout << "AutoSolve Active\n";
		if (tiles != NULL)
		{
			for (int i = 0; i < 3; i++)
			{
				if (tiles[i] != NULL) delete tiles[i];
			}
			delete tiles;
		}
	}

	//clean memory
	if (tiles != NULL)
	{
		for (int i = 0; i < 3; i++)
		{
			if (tiles[i] != NULL) delete tiles[i];
		}
		delete tiles;
	}
}
