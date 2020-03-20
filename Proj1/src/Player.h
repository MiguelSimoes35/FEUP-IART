#pragma once

#include <string>

#include "Piece.h"

using namespace std;

class Player
{
	int nr; //Player 1 or 2
	Piece pieces[16];
public:
	Player();
};

