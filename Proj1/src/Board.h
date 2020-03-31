#pragma once

#include "Piece.h"
#include "Node.h"
#include "algorithms.h"

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
	void reach_endzone(int o_line, char o_col);
	void new_checkers_p1();
	void new_checkers_p2();

	//to be used by the computer
	int evalGameState(bool player1);
	void generateTree(bool player1);
	char colToChar(int col);
	bool can_move_player1(int o_line, char o_col, int d_line, char d_col);
	Piece getCell(int line, int col);
	bool can_move_player2(int o_line, char o_col, int d_line, char d_col);
	void new_checkers_c1();
	void new_checkers_c2();
	void generateTree_d1(bool player1);
	void generateTree_d2(bool player1);

	void recapture_player1(int o_line, int o_col);
	void recapture_player2(int o_line, int o_col);
};