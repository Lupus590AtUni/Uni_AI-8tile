#include "AStar.h"
#include "EightTile.h"

#include <math.h>
#include <iostream>
#include <conio.h>
#include "NA_MathsLib.h"
#include "NA_Timer.h"

using std::cout;

extern EightTile myPuzzle;

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

	NA_Timer timer;
	timer.setDuration(0.5); // in seconds
	bool solved = false;
	while (!solved)
	{
		timer.restart();

		cout << "press any key to interrupt\n";
		if (_kbhit())
		{
			_getch(); //discard the key which was used to interrupt
			break;
		}



		timer.waitForElapse();

	}

}
