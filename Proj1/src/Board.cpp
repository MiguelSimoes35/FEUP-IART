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
	game_state[2][4] = Piece(1);
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

bool Board::check_piece1(int o_line, char o_col) {
	int o_column = int(o_col) - 65;
	if (game_state[o_line - 1][o_column].getPlayer() == 1) {
		return true;
	}
	return false;
}

bool Board::check_piece2(int o_line, char o_col) {
	int o_column = int(o_col) - 65;
	if (game_state[o_line - 1][o_column].getPlayer() == 2) {
		return true;
	}
	return false;
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
					cout << "ERROR 8!" << endl;
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
					cout << "ERROR 9!" << endl;
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
			//invalid line selection
			cout << "ERROR 7!" << endl;
		}
		break;
	}
	default:
		//invalid move
		//error
		break;
	}
}


void Board::move_player2(int o_line, char o_col, int d_line, char d_col) {
	int delta_line = d_line - o_line;

	int d_column = int(d_col) - 65;
	int o_column = int(o_col) - 65;
	int delta_col = d_column - o_column;

	switch (delta_line) {
	case 1: {
		if ((delta_col == -1) || (delta_col == 0) || (delta_col == 1)) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(2);
			}
			else {
				//error
				//moving to a non-empty cell
				cout << "ERROR 31!" << endl;
			}
		}
		else {
			//error
			//invalid move
			cout << "ERROR 32!" << endl;
		}
		break;
	}
	case 2: {
		if (delta_col == -2) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[o_line][d_column + 1].getPlayer() == 2) {

					game_state[o_line - 1][o_column].setPlayer(0);
					game_state[d_line - 1][d_column].setPlayer(2);
				}
				else {
					//error
					//not jumping over one of your's piece
					cout << "ERROR 33!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 34!" << endl;
			}
		}
		else if (delta_col == 0) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[o_line][d_column].getPlayer() == 2) {

					game_state[o_line - 1][o_column].setPlayer(0);
					game_state[d_line - 1][d_column].setPlayer(2);
				}
				else {
					//error
					//not jumping over one of your's piece
					cout << "ERROR 35!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 36!" << endl;
			}
		}
		else if (delta_col == 2) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[o_line][d_column - 1].getPlayer() == 2) {

					game_state[o_line - 1][o_column].setPlayer(0);
					game_state[d_line - 1][d_column].setPlayer(2);
				}
				else {
					//error
					//not jumping over one of your's piece
					cout << "Error 37!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 38!" << endl;
			}
		}
		else {
			//error
			//invalid line selection
			cout << "ERROR 39!" << endl;
		}
		break;
	}
	default:
		//error
		//invalid_move
		break;
	}
}



void Board::capture_player1(int o_line, char o_col, int d_line, char d_col) {
	int delta_line = d_line - o_line;

	int d_column = int(d_col) - 65;
	int o_column = int(o_col) - 65;
	int delta_col = d_column - o_column;

	switch (delta_line) {
	case -2: {
		if (delta_col == -2) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[d_line][d_column + 1].getPlayer() == 2) {

					game_state[o_line - 1][o_column].setPlayer(0);
					game_state[d_line - 1][d_column].setPlayer(1);
					game_state[d_line][d_column + 1].setPlayer(0);
				}
				else {
					//error
					//not capturing opponent's piece
					cout << "ERROR 11!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 12!" << endl;
			}
		}
		else if (delta_col == 0) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[d_line][d_column].getPlayer() == 2) {

					game_state[o_line - 1][o_column].setPlayer(0);
					game_state[d_line - 1][d_column].setPlayer(1);
					game_state[d_line][d_column].setPlayer(0);
				}
				else {
					//error
					//not capturing opponent's piece
					cout << "ERROR 13!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 14!" << endl;
			}
		}
		else if (delta_col == 2) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[d_line][d_column - 1].getPlayer() == 2) {

					game_state[o_line - 1][o_column].setPlayer(0);
					game_state[d_line - 1][d_column].setPlayer(1);
					game_state[d_line][d_column - 1].setPlayer(0);
				}
				else {
					//error
					//not capturing opponent's piece
					cout << "Error 15!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 16!" << endl;
			}
		}
		else {
			//error
			//invalid move
			cout << "ERROR 17!" << endl;
		}
		break;
	}
	case 0: {
		if (delta_col == -2) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[d_line-1][d_column+1].getPlayer() == 2) {

					game_state[d_line - 1][d_column].setPlayer(1);
					game_state[d_line - 1][d_column + 1].setPlayer(0);
					game_state[o_line-1][o_column].setPlayer(0);
				}
				else {
					//error
					//not capturing opponent's piece
					cout << "Error 18!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 19!" << endl;
			}
		}
		else if (delta_col == 2) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[d_line - 1][d_column - 1].getPlayer() == 2) {

					game_state[d_line - 1][d_column].setPlayer(1);
					game_state[d_line - 1][d_column - 1].setPlayer(0);
					game_state[o_line - 1][o_column].setPlayer(0);
				}
				else {
					//error
					//not capturing opponent's piece
					cout << "Error 20!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 21!" << endl;
			}
		}
		else {
			//error
			//invalid line selection
		}
		break;
	}
	default:
		//error
		//invalid move
		break;
	}
}

void Board::capture_player2(int o_line, char o_col, int d_line, char d_col) {
	int delta_line = d_line - o_line;

	int d_column = int(d_col) - 65;
	int o_column = int(o_col) - 65;
	int delta_col = d_column - o_column;

	switch (delta_line) {
	case 2: {
		if (delta_col == -2) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[o_line][d_column + 1].getPlayer() == 1) {

					game_state[o_line - 1][o_column].setPlayer(0);
					game_state[d_line - 1][d_column].setPlayer(2);
					game_state[o_line][d_column + 1].setPlayer(0);
				}
				else {
					//error
					//not capturing opponent's piece
					cout << "ERROR 41!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 42!" << endl;
			}
		}
		else if (delta_col == 0) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[o_line][d_column].getPlayer() == 1) {

					game_state[o_line - 1][o_column].setPlayer(0);
					game_state[d_line - 1][d_column].setPlayer(2);
					game_state[o_line][d_column].setPlayer(0);
				}
				else {
					//error
					//not capturing opponent's piece
					cout << "ERROR 43!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 44!" << endl;
			}
		}
		else if (delta_col == 2) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[o_line][d_column - 1].getPlayer() == 1) {

					game_state[o_line - 1][o_column].setPlayer(0);
					game_state[d_line - 1][d_column].setPlayer(2);
					game_state[o_line][d_column - 1].setPlayer(0);
				}
				else {
					//error
					//not capturing opponent's piece
					cout << "Error 45!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 46!" << endl;
			}
		}
		else {
			//error
			//invalid move
			cout << "ERROR 47!" << endl;
		}
		break;
	}
	case 0: {
		if (delta_col == -2) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[d_line - 1][d_column + 1].getPlayer() == 1) {

					game_state[d_line - 1][d_column].setPlayer(2);
					game_state[d_line - 1][d_column + 1].setPlayer(0);
					game_state[o_line - 1][o_column].setPlayer(0);
				}
				else {
					//error
					//not capturing opponent's piece
					cout << "Error 48!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 49!" << endl;
			}
		}
		else if (delta_col == 2) {
			if (game_state[d_line - 1][d_column].getPlayer() == 0) {
				if (game_state[d_line - 1][d_column - 1].getPlayer() == 1) {

					game_state[d_line - 1][d_column].setPlayer(2);
					game_state[d_line - 1][d_column - 1].setPlayer(0);
					game_state[o_line - 1][o_column].setPlayer(0);
				}
				else {
					//error
					//not capturing opponent's piece
					cout << "Error 50!" << endl;
				}
			}
			else {
				//error
				//moving to a non-empty cell...
				cout << "ERROR 51!" << endl;
			}
		}
		else {
			//error
			//invalid line selection
		}
		break;
	}
	default:
		//error
		//invalid move
		break;
	}
}
