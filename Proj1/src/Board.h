#pragma once

#include "Piece.h"

class Board {
	Piece game_state[8][8];
public:
	Board();
	void display_board();
	int count_p1_pieces();
	int count_p2_pieces();
	bool check_piece1(int o_line, char o_col);
	bool check_piece2(int o_line, char o_col);
	bool check_free(int o_line, char o_col);
	bool move_player1(int o_line, char o_col, int d_line, char d_col);
	bool move_player2(int o_line, char o_col, int d_line, char d_col);
	void recapture_player1(int o_line, int o_col);
	void reach_endzone(int o_line, char o_col);
	void new_checkers_p1();
	void new_checkers_p2();
};
