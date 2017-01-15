#include "fSnakeGame.h"

int maxheight, maxwidth;
void PlayGame();
int IsUserReady();
int AskUserToPlayAgain();
void ClearCentre();
int UserInput();

int main ()
{	
	if (IsUserReady() == 'y') // wait for confirmation of the user
	do {
		{
			fSnakeGame NewSnake;
			NewSnake.PlayGame();
		}
	}
	while (AskUserToPlayAgain() == 'y');
	return 0;
}



// clear the screen and centre the cursor
void ClearCentre(float x, float y)
{
	clear(); // clear the screen if the game is played for the 2nd time	
	initscr(); 
	noecho();
	getmaxyx(stdscr, maxheight, maxwidth);
	move((maxheight/y), (maxwidth/x));
}

// receive user confirmation
int UserInput()
{
	int UserInput = getch();
	refresh();
	endwin();
	clear();

	return UserInput;	
}

// start menu
int IsUserReady() // TODO: write more complete menu
{
	ClearCentre(3, 2.5);
	printw("Welcome to the Snake Game. Are you ready? (y/n)");
	return UserInput();
}

// game over menu
int AskUserToPlayAgain()
{
	ClearCentre(2.5, 2.5);
	printw("Do you want to play again? (y/n)");
	return UserInput();
}







