#ifndef _GHOST_H_
#define _GHOST_H_
using namespace std;

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "io.utils.h"
#include "Position.h"
#include "Board.h"
#include "object.h"

class Board;
class Ghost {
	Position Ghost_pos;
	Color color;
	char figure;
	char direction = 'd';
	bool bread = true;
public:
	void initGhost(Color ghostColor, char ghostFigure, int row, int col, char diraction);
	Position getPos() {
		return Ghost_pos;
	}
	void setGhostPos(int row, int col) {
		Ghost_pos.setPosition(row, col);
	}
	void setColor(Color c) {
		color = c;
	}
	Color getGhostColor() {
		return color;
	}
	char getDirection() {
		return direction;
	}
	char getFigure() {
		return figure;
	}
	void setFigure(const char c) {
		figure = c;
	}
	void moveGhost(char nextMove, Board& GameBoard);
	void CheckIfGhostTouchsAWall(char nextMove, Board& GameBoard);
	void touchTheGhostAndGoBack();
	void touchAWallAndRewind(Board& GameBoard);
	char diractionFromIntToChar(int d);
	void setDirection(char dir) {
		direction = dir;
	}
};

#endif