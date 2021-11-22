#ifndef _BOARD_H_
#define _BOARD_H_
using namespace std;
#include "io.utils.h"

enum { ROW = 25, COL = 80 };

class Game;
class Ghost;
class Board
{
	enum {
		BREADCRUMBS = '.', WALL = '#', PACMAN = '@', GHOST = '$'
	};
	char board[ROW][COL];

public:
	void initBoard();
	void setBreadcrumbs();
	void setWalls();
	void setSpaces();
	void drowBreadcrumbs(int row, int from, int to);
	void drowSpace(int row, int from, int to);
	void printBoard() const;
	char getCharFromBoard(int row, int col) const{
		return board[row][col];
	}
	void setCharToBoard(char symbol, int row, int col) {
		board[row][col] = symbol;
	}
	char checkAndReturnNextMove(char dir, int currRow, int currCol);
};

#endif