#ifndef _POSITION_H_
#define _POSITION_H_

using namespace std;
#include <iostream>
#include "io.utils.h"
#include "Board.h"
#include "object.h"

enum { ESC = 27 };
class Position
{
	int x;
	int y;
public:
	void draw(char ch);
	void updateMove(char direction, object obj);
	void setPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int GetRowPos() {
		return x;
	}
	int GetColPos() {
		return y;
	}

};

#endif
