#pragma once


enum move { NONE, UP, DOWN, LEFT, RIGHT };
class EightTile
{
public:
	EightTile();  //constructor
	void setMove(enum move);  //select direction
	void display(void);	//draw puzzle
	void swap(void); //swap blank with selected tile
	bool okLeft(void); //can I move left
	bool okRight(void);//can I move right
	bool okUp(void);//can I move up
	bool okDown(void);//can I move down

	int getX();
	int getY();
	int getSolution(int i, int j);
	int** getTilesCopy();

	void shuffle();
	

private:
	enum move myMove;
	int tiles[3][3];  //puzzle now
	int solution[3][3];//puzzle at start (solved).
	int x;  //blank x position
	int y;  //blank y position
	const int SHUFFLE_COUNT = 12;

};

