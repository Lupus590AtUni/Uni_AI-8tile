//#include <iostream>
#include "EightTile.h"
#include "HillClimb.h"
#include "AStar.h"
#include <conio.h>

#include <iostream>

using std::cout;


EightTile myPuzzle;//create class and init.

int main(void)
{
	//simple program to exercise puzzle by moving blank around
	//and drawing tiles
	char d; //keyboard interface valid values a,s,w,d	
	HillClimb hill;
	AStar aStar;

	// print controls
	cout << "controls\nwasd = move tiles\nh = activate hillclimbing, press any key to deactivate, it will also exit once it finds a solution\nj = activate A*, press any key to deactivate, it will also exit once it finds a solution\nt = shuffle the puzzle\n";

	while (true) //go forever
	{
		//cin >> d;
		d = _getch(); //http://www.cplusplus.com/forum/general/29137/#msg158172
		if (d == 'a') myPuzzle.setMove(LEFT);
		if (d == 'd') myPuzzle.setMove(RIGHT);
		if (d == 'w') myPuzzle.setMove(UP);
		if (d == 's') myPuzzle.setMove(DOWN);
		if (d == 'h') hill.solve();
		//if (d == 'j') aStar.solve();
		if (d == 't') myPuzzle.shuffle();
		myPuzzle.swap(); //move blank
		myPuzzle.display(); //draw puzzle

		// reprint controls
		cout << "controls\nwasd = move tiles\n"
			<<"h = activate hillclimbing, press any key to deactivate or wait for it to find a solution\n"<<
			"t = shuffle the puzzle\n";
		
	}
	return 0;
}//the end

//heuristic functions

int calcMissplaceCount(int** compare)
{
	int missplacedCount = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (compare[i][j] != myPuzzle.getSolution(i, j)) //if tile is not in it's proper location
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

int calcTotalManhatternDist(int** compare)
{
	int total = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (compare[i][j] != myPuzzle.getSolution(i, j)) //if tile is not in it's proper location
			{
				bool break_K_Loop = false; //breaking my variable naming convention in favour of readability
				//Find out how far it is from it's proper position
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						if (compare[i][j] == myPuzzle.getSolution(k, l)) //found it's proper position
						{
							total += abs(i - k)+ abs(j-l);

							//break loops somewhat nicely
							break_K_Loop = true;
							break; // break the l loop
						}
						if (break_K_Loop) break; //should never run, but just in case
					}
					if (break_K_Loop) break; // dist was found for this tile
				}
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		delete compare[i];
	}
	delete compare;

	return total;
}