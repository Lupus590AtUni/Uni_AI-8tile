#include "HillClimb.h"
#include "EightTile.h"

#include <math.h>
#include <iostream>
#include <conio.h>
#include "NA_MathsLib.h"
#include "NA_Timer.h"

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

	for (int i = 0; i < 3; i++)
	{
		delete compare[i];
	}
	delete compare;

	return missplacedCount;
}


void HillClimb::solve()
{
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
		int currentMissplacedCount = calcMissplaceCount();
		//cout << "HillClimb::solve - currentMissplacedCount: " << currentMissplacedCount;
		if (currentMissplacedCount == 0)
		{
			cout << "Solved\n";
			solved = true;
			break;
		}

		//only consider valid swaps
		int missplaceCountIfMove = currentMissplacedCount;
		move bestMove = NONE;
		int x = myPuzzle.getX();
		int y = myPuzzle.getY();
		if (myPuzzle.okDown())
		{
			myPuzzle.setMove(DOWN);
			myPuzzle.swap();
			int result = calcMissplaceCount(myPuzzle.getTilesCopy());
			if (result < currentMissplacedCount)//see if it's an improvment
			{
				missplaceCountIfMove = result;
				bestMove = DOWN;
			}
			myPuzzle.setMove(UP);
			myPuzzle.swap();//swap back so we can find best move
		}
		if (myPuzzle.okUp())
		{
			myPuzzle.setMove(UP);
			myPuzzle.swap();
			int result = calcMissplaceCount(myPuzzle.getTilesCopy());
			if (result < currentMissplacedCount)
			{
				missplaceCountIfMove = result;
				bestMove = UP;
			}
			myPuzzle.setMove(DOWN);
			myPuzzle.swap();
		}
		if (myPuzzle.okLeft())
		{
			myPuzzle.setMove(LEFT);
			myPuzzle.swap();
			int result = calcMissplaceCount(myPuzzle.getTilesCopy());
			if (result < currentMissplacedCount)
			{
				missplaceCountIfMove = result;
				bestMove = LEFT;
			}
			myPuzzle.setMove(RIGHT);
			myPuzzle.swap();
		}
		if (myPuzzle.okRight())
		{
			myPuzzle.setMove(RIGHT);
			myPuzzle.swap();
			int result = calcMissplaceCount(myPuzzle.getTilesCopy());
			if (result < currentMissplacedCount)
			{
				missplaceCountIfMove = result;
				bestMove = RIGHT;
			}
			myPuzzle.setMove(LEFT);
			myPuzzle.swap();
		}
		if (missplaceCountIfMove >= currentMissplacedCount)
		{
			//stuck, maybe try a random move?
			cout << "Stuck\n";

			extern NA_MathsLib maths;

			bool moveOK = false;
			move randomMove = (move)maths.dice(1,4);
			switch (randomMove)
			{
			case move::DOWN:
				moveOK = myPuzzle.okDown();
				break;
			case move::LEFT:
				moveOK = myPuzzle.okLeft();
				break;
			case move::UP:
				moveOK = myPuzzle.okUp();
				break;
			case move::RIGHT:
				moveOK = myPuzzle.okRight();
				break;

			default:
				cout << "HillClimb::solve Random move part when stuck - default used in switch"; // most of my defaults waitForElapse for imposibilities
				break;
			}
			if (moveOK)
			{
				myPuzzle.setMove(randomMove);
				myPuzzle.swap();
			}

			//break;
		}

		myPuzzle.setMove(bestMove);
		myPuzzle.swap();

		myPuzzle.display();
		cout << "AutoSolve Active\n";
		timer.waitForElapse();
		
	}

	
}
