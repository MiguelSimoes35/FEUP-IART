#pragma once

#include "Piece.h"

/*struct move {
	enum vertical {
		ord_1 = -1,
		jump_1 = -2,
		ord_2 = 1,
		jump_2 = 2
	};
	enum ordinary {
		left = -1,
		center = 0,
		right = 1
	};
	enum jumping {
		left = -2,
		center = 0,
		right = 2
	};
};*/

class Board {
	Piece game_state[8][8];
public:
	Board();
	void display_board();
	int count_p1_pieces();
	int count_p2_pieces();
	void move_player1(int o_line, char o_col, int d_line, char d_col);
	void move_player2(int o_line, char o_col, int d_line, char d_col);
};
