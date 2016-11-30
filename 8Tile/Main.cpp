//#include <iostream>
#include "EightTile.h"
#include "HillClimb.h"
#include <conio.h>

//using std::cin;


EightTile myPuzzle;//create class and init.

int main(void)
{
	//simple program to exercise puzzle by moving blank around
	//and drawing tiles
	char d; //keyboard interface valid values a,s,w,d	
	HillClimb ai;
	while (true) //go forever
	{

		//cin >> d;
		d = _getch(); //http://www.cplusplus.com/forum/general/29137/#msg158172
		if (d == 'a') myPuzzle.setMove(LEFT);
		if (d == 'd') myPuzzle.setMove(RIGHT);
		if (d == 'w') myPuzzle.setMove(UP);
		if (d == 's') myPuzzle.setMove(DOWN);
		if (d == 'g') ai.solve();
		myPuzzle.swap(); //move blank
		myPuzzle.display(); //draw puzzle
	}
	return 0;
}//the end
