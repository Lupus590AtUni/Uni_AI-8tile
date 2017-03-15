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




void HillClimb::solve()
{
	
	NA_Timer timer;
	timer.setDuration(0.5); // in seconds
	bool solved = false;

	// http://www.cprogramming.com/tutorial/function-pointers.html
	extern int (calcMissplaceCount) (int**);
	extern int (calcTotalManhatternDist)(int**);
	int(*heuristicFunction)(int**); 


	
	cout << "select heuristic function\nm = missplace count\nd = distance missplaced (manhattern distance)\n";
	char choice = 'a';
	while (!(choice == 'd' || choice == 'm'))
	{
		choice = _getch();
	}

	if (choice == 'd')
	{
		heuristicFunction = calcTotalManhatternDist;
	}
	else if(choice == 'm')
	{
		heuristicFunction = calcMissplaceCount;
	}
	else
	{
		cout << "HillClimb::solve - an impossible choice has been made when picking the heuristic function\n";
		return;
	}
	

	while (!solved)
	{
		timer.restart();
		cout << "press any key to interrupt\n";
		if (_kbhit())
		{
			_getch(); //discard the key which was used to interrupt
			break;
		}
		int heuristicValue = heuristicFunction(myPuzzle.getTilesCopy());
		//cout << "HillClimb::solve - heuristicValue: " << heuristicValue;
		if (heuristicValue == 0)
		{
			cout << "Solved\n";
			solved = true;
			break;
		}

		//only consider valid swaps
		int heuristicValueIfMove = heuristicValue;
		move bestMove = move::NONE;
		int x = myPuzzle.getX();
		int y = myPuzzle.getY();

		for (int m = move::UP; m < move::RIGHT + 1; m++)
		{
			cout << "m = " << m << "\n";
			if (myPuzzle.okMove((move)m))
			{
				myPuzzle.setMove((move)m);
				myPuzzle.swap();
				int result = heuristicFunction(myPuzzle.getTilesCopy());
				if (result < heuristicValue)//see if it's an improvment
				{
					heuristicValueIfMove = result;
					bestMove = (move)m;
				}

				int reverseMove;
				//due to the way the enum is layed out we can do this 'trick'
				if (m % 2 == 0) //if m is even
				{
					reverseMove = m - 1; //opposite move is the enum entry before m
				}
				else
				{
					reverseMove = m + 1; //opposite move is the enum entry after m
				}
				myPuzzle.setMove((move)reverseMove);
				myPuzzle.swap();//swap back so we can find best move
			}
		}
		

		if (heuristicValueIfMove >= heuristicValue)
		{
			//stuck, maybe try a random move?
			cout << "Stuck\n";

			extern NA_MathsLib na_maths;

			move randomMove = (move)na_maths.dice(1,4);
			if (myPuzzle.okMove(randomMove))
			{
				myPuzzle.setMove(randomMove);
				myPuzzle.swap();
			}

			//break;
		}

		myPuzzle.setMove(bestMove);
		myPuzzle.swap();

		myPuzzle.display();
		cout << "Hillclimb AutoSolve Active\n";
		timer.waitForElapse();
		
	}

	
}
