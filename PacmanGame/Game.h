#ifndef _GAME_H_
#define _GAME_H_
using namespace std;
#include <stdbool.h>
#include "io.utils.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Position.h"
#include "object.h"
#include "Board.h"

class Game {
	Pacman pacman;
	Ghost ghosts[2];
	Board GameBoard;
	enum { BREADCRUMBS = '.', WALL = '#', PACMAN = '@', GHOST = '$' };


public:
	Pacman& getPac() {
		return pacman;
	}
	void start();
	void CheckUserChoice(char& choice);
	void runTheGame(Color boardColor);
	void printMenu() const;
	void printColoredMenu() const;
	void ManageGhostMove();
	char ReturnNextGhostChar(int i);
	char ReturnNextPacmanChar(char key);
	bool ManagePacMove(char key);
	void initGame(Color pacColor, Color ghost0Color, Color ghost1Color);
	void pauseAllGame(char& key);
	void instructions(char& choice);
	bool IsPacmanMeetGhost(int i);
	void RunWithOrWithoutColors();
	void lose();
	void win();
};

#endif