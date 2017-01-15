# Snake Game

This is a version of the classic snake game, realised in accordance to Unreal coding standards and adapted from the cplusplusguy's tutorial. 

The code for this game is OS specific. To create the console app for Linus and Unix, I use here the non-standard library `ncurses.h`. For Windows, you will have to use `conio.h` and rewrite some commands. 

You will find below indications on how to run the file, some guidelines regarding `ncurses.h` and `conio.h`, as well as a short TODO list.

Useful links:

* [thecplusplusguy Youtube tutorial](https://www.youtube.com/watch?v=Cg_u60jX8Y4&list=PL2C01CC54638DD952)
* [Unreal coding standards cheatsheet](https://docs.unrealengine.com/latest/INT/Programming/Development/CodingStandard/index.html)

## The rules

There has never been a more simple game. Control the snake with the arrow keys and eat the fruit (*). When you eat the fruit, the snake's body gets longer and you gain 10 points. Every 100 points, the snake's speed will increase.

If you hit the borders of the game window or if the snake collapse into his own body, it's game over. 

## Run the file

Download the ncurses library, [here](https://www.gnu.org/software/ncurses/).

Clone the repository and run the following commands in the directory:
```
g++ fSnakeGame.cpp main.cpp -lncurses
./a.out
```

Enjoy!

## ncurses.h: main functions and how to

We are using ncurses for this game for two main reasons:
* we can easily move the cursor across the screen
* the program will detect and read the character input without the user having to press Enter. The user will be able to control the snake using only the arrow keys.

On Windows, we can simply use the conio.h header to have access to the following functions:
* `kbhit()`: detect character input
* `getch()`: get character input

You will find below a documentation for ncurses main functions. For more information, please refer to [ncurses official page](http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/). 

### Initialise a new game window:
In order to start using ncurses, you need to initialise the game window. You will need to run at least the following functions:
* `initscr()` to initialise the screen
* `getmaxyx(stdscr, y, x)` to initialise the window
* `refresh()` to refresh the screen and make sure previous changes are made visible
* `endwin` to exit from curses at the end of your program

### `move()` function:
Moves the cursor within the game window.

Either:
```c++
move(5, 8) // multidimensional array (y,x), starting at 0
printw("Your text to be moved")
```

Or: 
```c++
mvprintw(5, 8, "Your text to be moved");
```
Example:
```c++
int main ()
{
	initscr();
	mvprintw(10,4,"Hello World");
	refresh();
	getch(); // end the program when a key is pressed
	endwin();
	return 0;
}
```

### `getch()` function:
Gets user input (character) and returns an integer: the keycode of the character.

```c++
int main ()
{
	initscr();
	int c; // getch() returns the keycode and not the character itself 
	printw("Write something (ESC to escape): ");
	while ( (c=getch()) != 27 )
	{
		move(10,0);
		printw("Keycode: %d, and the character:%c",c,c); // convert integer into character
		move(0,0);
		printw("Write something (ESC to escape: ");
		refresh();
	}
	endwin();
	return 0;
}
```

Check all characters key codes [here](http://www.learncpp.com/cpp-tutorial/27-chars/).

### Attributes:
Attributes allow you to style in a limited way the output printed:
```c++
attron(A_BOLD); // set text to extra bright or bright
printw("Hello World");
attroff(A_BOLD); // turn bold off
```
You'll find more attributes [here](http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/attrib.html).

### Text and background colours:
You can customise the colours displayed in the terminal by initialising colour pairs. The first parameter of the pair is the text colour, the second parameter is the background colour.
```c++
int main ()
{
	initscr();
	start_color(); // we can now use colours in the terminal
	init_pair(1, COLOR_RED, COLOR_BLACK); 
	attron(COLOR_PAIR(1)); 
	printw("Hello World");
	attroff(COLOR_PAIR(1));
	refresh();
	getch();
	endwin();
	return 0;
}
```

### Other useful functions:
* `nodelay(stdscr, true)`: returns a boolean. When used with `getch()`, the program will not wait and will exit
* `keypad(stdscr, true)`: initialises the keypad and allows you to use arrow keys for instance	
* `noecho()`: called after initialisation, doesn't display the user input on the screen
* `curs_set(0)`: cursor is not displayed if set to 0
* `usleep()`: will put the program to sleep for microseconds, requires `<iostream>` library


## TODO list:
* write a more detailed menu with illustration.
* add a timer to create more challenge.
* add poisoned fruits to the window: the snake will have to avoid them. If eaten, it's game over.
* build a GUI.
