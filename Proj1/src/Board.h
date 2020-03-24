
#pragma once

#include "Piece.h"

class Board {
	Piece game_state[8][8];
public:
	Board();
	void display_board();
	int count_p1_pieces();
	int count_p2_pieces();
};
