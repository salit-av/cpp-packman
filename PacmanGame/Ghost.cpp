#include "Ghost.h"

void Ghost::initGhost(Color ghostColor, char ghostFigure, int row, int col, char diraction) {
	setGhostPos(row, col);
	setColor(ghostColor);
	setFigure(ghostFigure);
	setTextColor(getGhostColor());
	getPos().draw(getFigure());
	setDirection(diraction);
}

void Ghost::moveGhost(char nextMove, Board& GameBoard)
{
	int prevRow = Ghost_pos.GetRowPos();
	int prevCol = Ghost_pos.GetColPos();
	CheckIfGhostTouchsAWall(nextMove, GameBoard);
	Ghost_pos.updateMove(direction, GHOST);
	if (prevCol != Ghost_pos.GetColPos() || prevRow != Ghost_pos.GetRowPos()) {
		gotoxy(prevCol, prevRow);
		setTextColor(WHITE);
		cout << GameBoard.getCharFromBoard(prevRow, prevCol);
	}
	setTextColor(getGhostColor());
	Ghost_pos.draw(figure);
}

void Ghost::CheckIfGhostTouchsAWall(char nextMove, Board& GameBoard) {
	if (nextMove == GHOST) {
		touchTheGhostAndGoBack();
		nextMove = GameBoard.checkAndReturnNextMove(direction, Ghost_pos.GetRowPos(), Ghost_pos.GetColPos());
	}
	while (nextMove == '#' || GameBoard.checkAndReturnNextMove(direction, Ghost_pos.GetRowPos(), Ghost_pos.GetColPos()) == -1)
	{
		touchAWallAndRewind(GameBoard);
		nextMove = GameBoard.checkAndReturnNextMove(direction, Ghost_pos.GetRowPos(), Ghost_pos.GetColPos());
	}
}

void Ghost::touchTheGhostAndGoBack() {
	switch (direction) {
	case 'a': // LEFT
	case 'A': // LEFT
		direction = 'd';
		break;
	case 'x': // DOWN
	case 'X': // DOWN
		direction = 'w';
		break;
	case 'w': // UP
	case 'W': // UP
		direction = 'x';
		break;
	case 'd': // RIGHT
	case 'D': // RIGHT
		direction = 'a';
		break;
	}
}

void Ghost::touchAWallAndRewind(Board& GameBoard) {
	srand(time(NULL));
	int d = rand() % 4;
	char dir = diractionFromIntToChar(d);
	while (dir == direction) {
		d = rand() % 4;
		dir = diractionFromIntToChar(d);
	}
	direction = dir;
}

char Ghost::diractionFromIntToChar(int d) {
	switch (d) {
	case 0: // LEFT
		return 'a';
	case 1: // UP
		return 'w';
	case 2: // RIGHT
		return 'd';
	case 3: // DOWN
		return 'x';
	}
}