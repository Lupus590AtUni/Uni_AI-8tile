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
	cout << "controls\nwasd = move tiles\nh = activate hillclimbing, press any key to deactivate or wait for it to find a solution\nt = shuffle the puzzle\n";

	while (true) //go forever
	{
		//cin >> d;
		d = _getch(); //http://www.cplusplus.com/forum/general/29137/#msg158172
		if (d == 'a') myPuzzle.setMove(LEFT);
		if (d == 'd') myPuzzle.setMove(RIGHT);
		if (d == 'w') myPuzzle.setMove(UP);
		if (d == 's') myPuzzle.setMove(DOWN);
		if (d == 'h') hill.solve();
		if (d == 't') myPuzzle.shuffle();
		myPuzzle.swap(); //move blank
		myPuzzle.display(); //draw puzzle

		// reprint controls
		cout << "controls\nwasd = move tiles\nh = activate hillclimbing, press any key to deactivate or wait for it to find a solution\nt = shuffle the puzzle\n";
		
	}
	return 0;
}//the end
