#include "Pacman.h"

void Pacman::initPacman(Color pacColor, char pacFigure) {
	setArrowKeys("awdxsAWDXS");
	setPacPos(12, 4); //Set the pacman start position
	setColor(pacColor);
	setFigure(pacFigure);
	setTextColor(getPacColor());
	getPos().draw(getFigure());
	printPacFood();
	printPacLives();
	setTextColor(WHITE);
}

void Pacman::movePac(Board& GameBoard) {
	int prevRow = Pacman_pos.GetRowPos();
	int prevCol = Pacman_pos.GetColPos();
	Pacman_pos.updateMove(direction, PACMAN);
	if (prevCol != Pacman_pos.GetColPos() || prevRow != Pacman_pos.GetRowPos()) {
		gotoxy(prevCol, prevRow);
		GameBoard.setCharToBoard(' ', prevRow, prevCol);
		setTextColor(WHITE);
		cout << GameBoard.getCharFromBoard(prevRow, prevCol);
	}
	setTextColor(getPacColor());
	Pacman_pos.draw(figure);
}

char Pacman::getDirection(char key) {
	for (int i = 0; i < 10; i++)
	{
		if (key == arrowKeys[i])
			return arrowKeys[i];
	}
	return -1;
}

void Pacman::setArrowKeys(const char* keys) { // "awdxsAWDXS"
	arrowKeys[0] = keys[0];
	arrowKeys[1] = keys[1];
	arrowKeys[2] = keys[2];
	arrowKeys[3] = keys[3];
	arrowKeys[4] = keys[4];
	arrowKeys[5] = keys[5];
	arrowKeys[6] = keys[6];
	arrowKeys[7] = keys[7];
	arrowKeys[8] = keys[8];
	arrowKeys[9] = keys[9];
}