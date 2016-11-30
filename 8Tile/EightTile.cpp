#include "EightTile.h"
#include <iostream>

using std::cout;
using std::endl;

EightTile::EightTile()
{
	myMove = NONE;  //initialize member attributes
	
	/*tiles[0][0] = 0; tiles[1][0] = 1; tiles[2][0] = 2; //set up puzzle tiles
	tiles[0][1] = 3; tiles[1][1] = 4; tiles[2][1] = 5;
	tiles[0][2] = 6; tiles[1][2] = 7; tiles[2][2] = 8;*/

	tiles[0][0] = 1; tiles[1][0] = 4; tiles[2][0] = 2; //assigned problem
	tiles[0][1] = 3; tiles[1][1] = 5; tiles[2][1] = 8;
	tiles[0][2] = 6; tiles[1][2] = 0; tiles[2][2] = 7;

	solution[0][0] = 0; solution[1][0] = 1; solution[2][0] = 2; //set up solved puzzle tile positions
	solution[0][1] = 3; solution[1][1] = 4; solution[2][1] = 5;
	solution[0][2] = 6; solution[1][2] = 7; solution[2][2] = 8;

	//find blank position
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (tiles[i][j] == 0)
			{
				x = i;
				y = j;
				break;
			}
		}
	}

	display();
}

void EightTile::display(void)
//draw puzzle as it is now
{
	cout << tiles[0][0] << " " << tiles[1][0] << " " << tiles[2][0] << endl;
	cout << tiles[0][1] << " " << tiles[1][1] << " " << tiles[2][1] << endl;
	cout << tiles[0][2] << " " << tiles[1][2] << " " << tiles[2][2] << endl;
	cout << endl;
}
void EightTile::setMove(enum move m)
//sets which way you want to move
{
	myMove = m;
}
void EightTile::swap(void)
//attempts to move blank in direction set - up, down, left or right by doing a tile/blank swap
//can't move beyond edges of puzzle
{
	int temp;
	if (okLeft() & (myMove == LEFT)) {
		temp = tiles[x - 1][y];
		tiles[x - 1][y] = tiles[x][y];
		tiles[x][y] = temp;
		x = x - 1;

	}
	if (okRight() & (myMove == RIGHT)) {
		temp = tiles[x + 1][y];
		tiles[x + 1][y] = tiles[x][y];
		tiles[x][y] = temp;
		x = x + 1;

	}

	if (okUp() & (myMove == UP)) {
		temp = tiles[x][y - 1];
		tiles[x][y - 1] = tiles[x][y];
		tiles[x][y] = temp;
		y = y - 1;

	}
	if (okDown() & (myMove == DOWN)) {
		temp = tiles[x][y + 1];
		tiles[x][y + 1] = tiles[x][y];
		tiles[x][y] = temp;
		y = y + 1;

	}
}
bool EightTile::okLeft(void)
//can I move left?
{

	if (x > 0)
		return true; else return false;
}
bool EightTile::okRight(void)
//can I move right?
{
	if (x < 2)
		return true; else return false;
}
bool EightTile::okUp(void)
//can I move up?
{
	if (y > 0)
		return true; else return false;
}
bool EightTile::okDown(void)
//can I move down?
{
	if (y < 2)
		return true; else return false;
}

int EightTile::getX()
{
	return x;
}

int EightTile::getY()
{
	return y;
}

int EightTile::getSolution(int i, int j)
{
	return solution[i][j];
}

int** EightTile::getTilesCopy()
{
	int** copy;
	copy = new int*[3];
	for (int i = 0; i < 3; i++)
	{
		copy[i] = new int[3];
		for (int j = 0; j < 3; j++)
		{
			copy[i][j] = tiles[i][j];
		}
	}
	return copy;
}
