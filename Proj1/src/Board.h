#pragma once

#include "Piece.h"

#define MIN_COL		A
#define MIN_LINE	1
#define MAX_COL		H
#define MAX_LINE	8

class Board {
	Piece game_state[8][8];
public:
	Board();
	void display_board();
	int count_p1_pieces();
	int count_p2_pieces();
	void check_piece1(int o_line, char o_col);
	void check_piece2(int o_line, char o_col);
	void move_player1(int o_line, char o_col, int d_line, char d_col);
	void move_player2(int o_line, char o_col, int d_line, char d_col);
	void capture_player1(int o_line, char o_col, int d_line, char d_col);
	void capture_player2(int o_line, char o_col, int d_line, char d_col);
};
