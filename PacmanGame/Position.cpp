#include "Position.h"


void Position::draw(char ch) {
	gotoxy(y, x);
	cout << ch << endl;
}

void Position::updateMove(char dir, object obj) {
	switch (dir) {
	case 'a': // LEFT
	case 'A': // LEFT
		--y;
		if (y < 0 && obj == PACMAN) {
			y = COL - 1;
		}
		break;
	case 'x': // DOWN
	case 'X': // DOWN
		++x;
		if (x > ROW - 1 && obj == PACMAN) {
			x = 0;
		}
		break;
	case 'w': // UP
	case 'W': // UP
		--x;
		if (x < 0 && obj == PACMAN) {
			x = ROW - 1;
		}
		break;
	case 'd': // RIGHT
	case 'D': // RIGHT
		++y;
		if (y > COL - 1 && obj == PACMAN) {
			y = 0;
		}
		break;
	case 's': // PAUSE
	case 'S': // PAUSE
		break;
	}
}