#include "Board.h"

void Board::initBoard() {
	setWalls();
	setBreadcrumbs();
	setSpaces();
	printBoard();
}

void Board::setWalls() {
	int i, j;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			board[i][j] = WALL;
		}
	}
}

void Board::setBreadcrumbs() {
	drowBreadcrumbs(1, 3, 74);

	drowBreadcrumbs(2, 3, 74);

	drowBreadcrumbs(3, 3, 4);
	drowBreadcrumbs(3, 60, 61);
	drowBreadcrumbs(3, 73, 74);

	drowBreadcrumbs(4, 3, 4);
	drowBreadcrumbs(4, 60, 61);
	drowBreadcrumbs(4, 73, 74);

	drowBreadcrumbs(5, 3, 4);
	drowBreadcrumbs(5, 60, 61);
	drowBreadcrumbs(5, 73, 74);

	drowBreadcrumbs(6, 3, 4);
	drowBreadcrumbs(6, 10, 53);
	drowBreadcrumbs(6, 60, 61);
	drowBreadcrumbs(6, 73, 74);

	drowBreadcrumbs(7, 3, 4);
	drowBreadcrumbs(7, 10, 11);
	drowBreadcrumbs(7, 52, 53);
	drowBreadcrumbs(7, 60, 61);
	drowBreadcrumbs(7, 73, 74);

	drowBreadcrumbs(8, 3, 4);
	drowBreadcrumbs(8, 10, 11);
	drowBreadcrumbs(8, 52, 53);
	drowBreadcrumbs(8, 60, 64);
	drowBreadcrumbs(8, 73, 74);

	drowBreadcrumbs(9, 3, 4);
	drowBreadcrumbs(9, 10, 11);
	drowBreadcrumbs(9, 52, 53);
	drowBreadcrumbs(9, 60, 64);
	drowBreadcrumbs(9, 73, 74);

	drowBreadcrumbs(10, 3, 4);
	drowBreadcrumbs(10, 10, 11);
	drowBreadcrumbs(10, 52, 53);
	drowBreadcrumbs(10, 63, 64);
	drowBreadcrumbs(10, 73, 74);

	drowBreadcrumbs(11, 3, 4);
	drowBreadcrumbs(11, 10, 11);
	drowBreadcrumbs(11, 52, 53);
	drowBreadcrumbs(11, 63, 64);
	drowBreadcrumbs(11, 73, 74);

	drowBreadcrumbs(12, 0, 79);

	drowBreadcrumbs(13, 0, 79);

	drowBreadcrumbs(14, 3, 4);
	drowBreadcrumbs(14, 10, 11);
	drowBreadcrumbs(14, 20, 21);
	drowBreadcrumbs(14, 52, 53);
	drowBreadcrumbs(14, 73, 74);

	drowBreadcrumbs(15, 3, 4);
	drowBreadcrumbs(15, 10, 11);
	drowBreadcrumbs(15, 20, 21);
	drowBreadcrumbs(15, 52, 53);
	drowBreadcrumbs(15, 73, 74);

	drowBreadcrumbs(16, 3, 4);
	drowBreadcrumbs(16, 10, 11);
	drowBreadcrumbs(16, 20, 21);
	drowBreadcrumbs(16, 52, 53);
	drowBreadcrumbs(16, 73, 74);

	drowBreadcrumbs(17, 3, 4);
	drowBreadcrumbs(17, 10, 11);
	drowBreadcrumbs(17, 20, 21);
	drowBreadcrumbs(17, 52, 53);
	drowBreadcrumbs(17, 73, 74);

	drowBreadcrumbs(18, 0, 79);

	drowBreadcrumbs(19, 0, 79);

	drowBreadcrumbs(20, 3, 4);
	drowBreadcrumbs(20, 20, 21);
	drowBreadcrumbs(20, 36, 37);
	drowBreadcrumbs(20, 49, 50);
	drowBreadcrumbs(20, 58, 59);
	drowBreadcrumbs(20, 73, 74);

	drowBreadcrumbs(21, 3, 4);
	drowBreadcrumbs(21, 20, 21);
	drowBreadcrumbs(21, 36, 37);
	drowBreadcrumbs(21, 49, 50);
	drowBreadcrumbs(21, 58, 59);
	drowBreadcrumbs(21, 73, 74);

	drowBreadcrumbs(22, 3, 4);
	drowBreadcrumbs(22, 20, 21);
	drowBreadcrumbs(22, 36, 37);
	drowBreadcrumbs(22, 49, 50);
	drowBreadcrumbs(22, 58, 59);
	drowBreadcrumbs(22, 73, 74);

	drowBreadcrumbs(23, 0, 79);
}

void Board::drowBreadcrumbs(int row, int from, int to) {
	while (from <= to) {
		board[row][from] = BREADCRUMBS;
		from++;
	}
}

void Board::setSpaces() {
	/* Error Space*/
	drowSpace(8, 13, 50);
	drowSpace(9, 13, 50);
	drowSpace(10, 13, 50);
}

void Board::drowSpace(int row, int from, int to) {
	while (from <= to) {
		board[row][from] = ' ';
		from++;
	}
}

void Board::printBoard() const {
	int i, j;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
}

char Board::checkAndReturnNextMove(char dir, int currRow, int currCol) {

	if (dir == 'a' || dir == 'A') {//When the object goes left
		if (currCol > 0) {
			return(getCharFromBoard(currRow, currCol - 1));
		}
		else
			return -1;
	}
	if (dir == 'd' || dir == 'D') { //When the object goes right
		if (currCol < COL - 1) {
			return(getCharFromBoard(currRow, currCol + 1));
		}
		else
			return -1;
	}
	if (dir == 'w' || dir == 'W') { //when the object goes up
		if (currRow > 0) {
			return(getCharFromBoard(currRow - 1, currCol));
		}
		else
			return -1;
	}
	if (dir == 'x' || dir == 'X') { //When the object goes down
		if (currRow < ROW - 1) {
			return(getCharFromBoard(currRow + 1, currCol));
		}
		else
			return -1;
	}
	return 0;
}