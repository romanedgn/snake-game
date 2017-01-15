#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#ifndef FSNAKEGAME_H
#define FSNAKEGAME_H

struct CharPosition 
{
	int x, y;
	CharPosition(int col, int row);
	CharPosition();
};

class fSnakeGame 
{
private:
	int score, del, maxwidth, maxheight;
	char direction, partchar, edgechar, fruitchar;
	// partchar is the character representing the snake's body
	// edgechar is the character representing the edge of the game window
	// fruitchar is the character representing the fruit
	// del stands for delay
	bool bEatsFruit;
	CharPosition fruit; // need to clarify this combination 
	std::vector<CharPosition> snake; // represent the snake's body

	void InitGameWindow();
	void DrawWindow();  
	void DrawSnake();
	void PrintScore();
	void PositionFruit();
	bool FatalCollision();
	void MoveSnake();
	bool GetsFruit();

public:
	fSnakeGame();
	~fSnakeGame(); // destructor for cleanup and memory deallocation
	void PlayGame();
};


#endif