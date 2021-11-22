#include "Game.h"


void Game::start() {
	printMenu();
	char choice;
	cin >> choice;
	CheckUserChoice(choice);
	while (choice != '3') {
		switch (choice) {
		case '1':
			RunWithOrWithoutColors();
			break;
		case '2':
			instructions(choice);
			break;
		}

		lose();
		win();


		printMenu();
		cin >> choice;
		CheckUserChoice(choice);
		/* reset game */
		pacman.resetPacmanLives();
		pacman.resetPacmanFood();
	}
}

void Game::printMenu() const {
	system("cls");
	cout << "Please insert your choice:\n"
		"1. Start a new game.\n"
		"2. Present instructions and keys\n"
		"3. Exit\n";
}

void Game::CheckUserChoice(char& choice) {
	while (choice != '1' && choice != '2' && choice != '3') {
		printMenu();
		cout << "Invalid choice, please enter a valid number." << endl;
		cin >> choice;
	}
}

void Game::RunWithOrWithoutColors() {
	system("cls");
	printColoredMenu();
	char choice;
	cin >> choice;
	while (choice != '1' && choice != '2') {
		cout << "Invalid choice, please enter a valid number." << endl;
		cin >> choice;
	}
	if (choice == '1') {
		initGame(LIGHTBLUE, LIGHTMAGENTA, RED);
		runTheGame(LIGHTBLUE);
	}
	if (choice == '2')
	{
		initGame(WHITE, WHITE, WHITE);
		runTheGame(WHITE);
	}
}

void Game::printColoredMenu() const {
	cout << "Run the game with or without colors?" << endl;
	cout << "1. With colors" << endl;
	cout << "2. Withous colors" << endl;
}

void Game::instructions(char& choice) {
	system("cls");
	cout << "WELCOME TO PACMAN GAME!" << endl;
	cout << "As a pacman player, you have to eat all the bread crumbs all over the board." << endl;
	cout << "But it not that easy! you have to run away from the ghosts that can eat you easly." << endl;
	cout << "If you succeed, An appropriate message will appear on the board. If not, you can try again and again." << endl;
	cout << "These are the keyboard keys you can use:" << endl;
	cout << "A or a - for going left" << endl;
	cout << "W or w - for going up" << endl;
	cout << "D or d - for going right" << endl;
	cout << "X or x - for going down" << endl;
	cout << "S or s - for stop the pacman only" << endl;
	cout << "ESC - for stop the all game" << endl;
	cout << "Good luck! Press any key to return to menu" << endl;
	cin >> choice;

}

void Game::initGame(Color pacColor, Color ghost0Color, Color ghost1Color) {
	system("cls");
	GameBoard.initBoard();
	pacman.initPacman(pacColor, PACMAN);
	ghosts[0].initGhost(ghost0Color, GHOST, 10, 10, 'd');
	ghosts[1].initGhost(ghost1Color, GHOST, 12, COL - 1, 'd');
}

void Game::runTheGame(Color boardColor) {
	hideCursor();
	char key = 0;
	char dir = -1;
	bool PacMove = false, GhostMove = true;
	while (pacman.getPacmanLives() != 0 && !pacman.PacAteAllBread()) {
		if (_kbhit()) {
			key = _getch();
			if (key == ESC) {
				pauseAllGame(key);
			}
			else if ((dir = pacman.getDirection(key)) != -1) {
				pacman.setDirection(dir);
			}
			else {
				break;
			}
		}
		if (dir != -1) {
			PacMove = ManagePacMove(dir);
			if (PacMove) {
				pacman.movePac(GameBoard);
				setTextColor(WHITE);
			}
		}
		// check if we need to move the ghosts
		if (GhostMove) {
			ManageGhostMove();
			GhostMove = false;
			setTextColor(WHITE);
		}
		else {
			GhostMove = true;
		}

		Sleep(160);
		setTextColor(boardColor);
		pacman.printPacFood();
		pacman.printPacLives();
		setTextColor(WHITE);
	}
}

bool Game::IsPacmanMeetGhost(int i) {
	if (pacman.getPos().GetRowPos() == ghosts[i].getPos().GetRowPos() &&
		pacman.getPos().GetColPos() == ghosts[i].getPos().GetColPos())
		return true;
	return false;
}

bool Game::ManagePacMove(char key) {
	char NextKey = ReturnNextPacmanChar(key);

	if (NextKey == '#') {
		return false;
	}
	for (int i = 0; i < 2; i++) {
		if (IsPacmanMeetGhost(i)) {
			pacman.setPacmanLives();
			pacman.setPacPos(12, 4);
			pacman.getPos().draw(pacman.getFigure());
			pacman.setDirection('s');
		}
	}
	if (GameBoard.getCharFromBoard(pacman.getPos().GetRowPos(), pacman.getPos().GetColPos()) == '.')
		pacman.addFoodCollected();

	return true;
}

char Game::ReturnNextPacmanChar(char key) {
	char res;
	Position currPos = pacman.getPos();
	res = GameBoard.checkAndReturnNextMove(pacman.getDirection(key), currPos.GetRowPos(), currPos.GetColPos());
	return res;
}

char Game::ReturnNextGhostChar(int i) {
	char res;
	Position currPos = ghosts[i].getPos();
	res = GameBoard.checkAndReturnNextMove(ghosts[i].getDirection(), currPos.GetRowPos(), currPos.GetColPos());
	return res;
}

void Game::ManageGhostMove() {
	ghosts[0].moveGhost(ReturnNextGhostChar(0), GameBoard);
	ghosts[1].moveGhost(ReturnNextGhostChar(1), GameBoard);
}

void Game::pauseAllGame(char& key) { //come back
	key = ' ';
	gotoxy(16, 10);
	cout << "THE GAME PAUSED! Press ESC again";
	while (key != ESC)
	{
		key = _getch();
	}
	gotoxy(16, 10);
	cout << "                                  ";
}

void Game::lose() {
	char temp;
	if (pacman.getPacmanLives() == 0) {
		system("cls");
		cout << "################################################" << endl;
		cout << "#             GAME OVER - YOU LOSE!            #" << endl;
		cout << "#   press any key to return to the main menu   #" << endl;
		cout << "################################################" << endl;
		cin >> temp;
	}

}

void Game::win() {
	char temp;
	if (pacman.PacAteAllBread()) {
		system("cls");
		cout << "################################################" << endl;
		cout << "#                  YOU WON!                    #" << endl;
		cout << "#   press any key to return to the main menu   #" << endl;
		cout << "################################################" << endl;
		cin >> temp;
	}
}