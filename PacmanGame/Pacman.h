#ifndef _PACMAN_H_
#define _PACMAN_H_
using namespace std;

#include <iostream>
#include "io.utils.h"
#include "Position.h"
#include "Board.h"
#include "object.h"
#include "Color.h"

class Board;
class Pacman
{
private:
	int lives = 3;
	int food_collected = 0;
	Position Pacman_pos;
	Color color;
	char figure;
	char arrowKeys[10];
	char direction;
public:
	void setArrowKeys(const char* keys); // Sets the arrowkeys the player can play with.
	void initPacman(Color pacColor, char pacFigure);
	Position getPos() {
		return Pacman_pos;
	}
	void setPacPos(int row, int col) {
		Pacman_pos.setPosition(row, col);
	}
	void setColor(Color c) {
		color = c;
	}
	Color getPacColor() {
		return color;
	}
	void setFigure(const char c) {
		figure = c;
	}
	char getFigure() {
		return figure;
	}
	void addFoodCollected() {
		food_collected++;
	}
	int getPacFood() {
		return food_collected;
	}
	void movePac(Board& GameBoard);
	char getDirection(char key);
	void setDirection(char dir) {
		direction = dir;
	}
	int getPacmanLives() {
		return lives;
	}
	void setPacmanLives() {
		lives--;
	}
	void resetPacmanLives() {
		lives = 3;
	}
	void resetPacmanFood() {
		food_collected = 0;
	}
	void printPacLives() const{
		gotoxy(24, 9);
		cout << "PACMAN'S LIVES: " << lives;
	}
	void printPacFood() const{
		gotoxy(20, 8);
		cout << "YOU COLLECTED " << food_collected << " BREADCRUMBS";
	}

	bool PacAteAllBread() {
		if (food_collected == 744)
			return true;
		else {
			return false;
		}
	}

};

#endif