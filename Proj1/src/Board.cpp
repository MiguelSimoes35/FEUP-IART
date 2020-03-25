#include "Board.h"
#include <iostream>

using namespace std;

Board::Board() {
	//Initialize p1 pieces
	for (int i = 5; i < 8; i++) {
		for (int j = 1; j < 3; j++) {
			game_state[i][j] = Piece(1);
		}
	}
	for (int i = 5; i < 8; i++) {
		for (int j = 5; j < 7; j++) {
			game_state[i][j] = Piece(1);
		}
	}
	for (int i = 6; i < 8; i++) {
		for (int j = 3; j < 5; j++) {
			game_state[i][j] = Piece(1);
		}
	}

	//Initialize p2 pieces
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 3; j++) {
			game_state[i][j] = Piece(2);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 5; j < 7; j++) {
			game_state[i][j] = Piece(2);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 3; j < 5; j++) {
			game_state[i][j] = Piece(2);
		}
	}
}

void Board::display_board() {
	cout << "     a   b   c   d   e   f   g   h " << endl;
	cout << "   ---------------------------------" << endl;
	for (int i = 0; i < 8; i++) {
		cout << " " << i + 1 << " |";
		for (int j = 0; j < 8; j++) {
			cout << " " << game_state[i][j].getCharacter() << " |";
		}
		cout << endl << "   ---------------------------------" << endl;
	}
}

int Board::count_p1_pieces() {
	int counter = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (game_state[i][j].getPlayer() == 1) {
				counter++;
			}
		}
	}

	return counter;
}

int Board::count_p2_pieces() {
	int counter = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (game_state[i][j].getPlayer() == 2) {
				counter++;
			}
		}
	}

	return counter;
}

void Board::move_player1(int o_line, char o_col, int d_line, char d_col) {
	int delta_line = d_line - o_line;

	int d_column = int(d_col) - 65;
	int o_column = int(o_col) - 65;
	int delta_col = d_column - o_column;

	switch (delta_line) {
	case -1: {
		if ((delta_col == -1) || (delta_col == 0) || (delta_col == 1)) {

			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(1);
			}
			else {
				//error
				//moving to a non-empty cell
				cout << "ERROR 1!" << endl;
			}
		}
		else {
			//error
			//invalid move
			cout << "ERROR 2!" << endl;
		}
		break;
	}
	case -2: {
		if (delta_col == -2) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[d_line][d_column + 1].getPlayer() == 1) {

					game_state[o_line - 1][o_column].setPlayer(0);
					game_state[d_line - 1][d_column].setPlayer(1);
				}
				else {
					//error
					//not jumping over one of your's piece
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 3!" << endl;
			}
		}
		else if (delta_col == 0) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[d_line][d_column].getPlayer() == 1) {

					game_state[o_line - 1][o_column].setPlayer(0);
					game_state[d_line - 1][d_column].setPlayer(1);
				}
				else {
					//error
					//not jumping over one of your's piece
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 4!" << endl;
			}
		}
		else if (delta_col == 2) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[d_line][d_column - 1].getPlayer() == 1) {

					game_state[o_line - 1][o_column].setPlayer(0);
					game_state[d_line - 1][d_column].setPlayer(1);
				}
				else {
					//error
					//not jumping over one of your's piece
					cout << "Error 5!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 6!" << endl;
			}
		}
		else {
			//error
			//invalid move
			cout << "ERROR 7!" << endl;
		}
		break;
	}
	}
}

void Board::move_player2(int o_line, char o_col, int d_line, char d_col) {

}
