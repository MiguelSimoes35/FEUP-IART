#pragma once

#include <iostream>

#include "consts.h"

using namespace std;

class Board
{
	int game_state[8][8];
public:
	Board();
	void fillBoard();
};

