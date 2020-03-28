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
	cout << "     A   B   C   D   E   F   G   H " << endl;
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


bool Board::check_free(int o_line, char o_col) {
	int o_column = int(o_col) - 65;
	if (game_state[o_line - 1][o_column].getPlayer() == 0) {
		return true;
	}
	return false;
}




bool Board::move_player1(int o_line, char o_col, int d_line, char d_col) {
	int delta_line = d_line - o_line;

	int d_column = int(d_col) - 65;
	int o_column = int(o_col) - 65;
	int delta_col = d_column - o_column;

	switch (delta_line) {
	case -1: {
		if ((delta_col == -1) || (delta_col == 0) || (delta_col == 1)) {

			game_state[o_line - 1][o_column].setPlayer(0);
			game_state[d_line - 1][d_column].setPlayer(1);
			return true;
		}
		else {
			//error
			//invalid column selection
			cout << "Error! You have selected an invalid column to move." << endl;
			return false;
		}
		break;
	}
	case -2: {
		if (delta_col == -2) {
			if (game_state[d_line][d_column + 1].getPlayer() == 1) {

				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(1);
				return true;
			}
			else if (game_state[d_line][d_column + 1].getPlayer() == 2) {

				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(1);
				game_state[d_line][d_column + 1].setPlayer(0);
				return true;
			}
			else {
				//error
				//not jumping over a piece
				cout << "Error! You're not jumping over a piece." << endl;
				return false;
			}
		}
		else if (delta_col == 0) {
			if (game_state[d_line][d_column].getPlayer() == 1) {

				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(1);
				return true;
			}
			else if (game_state[d_line][d_column].getPlayer() == 2) {

				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(1);
				game_state[d_line][d_column].setPlayer(0);
				return true;
			}
			else {
				//error
				//not jumping over a piece
				cout << "Error! You're not jumping over a piece." << endl;
				return false;
			}
		}
		else if (delta_col == 2) {
			if (game_state[d_line][d_column - 1].getPlayer() == 1) {

				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(1);
				return true;
			}
			else if (game_state[d_line][d_column - 1].getPlayer() == 2) {

				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(1);
				game_state[d_line][d_column - 1].setPlayer(0);
				return true;
			}
			else {
				//error
				//not jumping over a piece
				cout << "Error! You're not jumping over a piece." << endl;
				return false;
			}
		}
		else {
			//error
			//invalid column selection
			cout << "Error! You have selected an invalid column to move." << endl;
			return false;
		}
		break;
	}
	case 0: {
		if (delta_col == -2) {
			if (game_state[d_line - 1][d_column + 1].getPlayer() == 2) {

				game_state[d_line - 1][d_column].setPlayer(1);
				game_state[d_line - 1][d_column + 1].setPlayer(0);
				game_state[o_line - 1][o_column].setPlayer(0);
				return true;
			}
			else {
				//error
				//not capturing opponent's piece
				cout << "Error! You're not capturing opponent's piece" << endl;
				return false;
			}
		}
		else if (delta_col == 2) {
			if (game_state[d_line - 1][d_column - 1].getPlayer() == 2) {

				game_state[d_line - 1][d_column].setPlayer(1);
				game_state[d_line - 1][d_column - 1].setPlayer(0);
				game_state[o_line - 1][o_column].setPlayer(0);
				return true;
			}
			else {
				//error
				//not capturing opponent's piece
				cout << "Error! You're not capturing opponent's piece" << endl;
				return false;
			}
		}
		else {
			//error
			//invalid column selection
			cout << "Error! You have selected an invalid column to move." << endl;
			return false;
		}
		break;
	}
	default:
		//error
		//invalid line selection
		cout << "Error! You have selected an invalid line to move." << endl;
		return false;
		break;
	}
}


bool Board::move_player2(int o_line, char o_col, int d_line, char d_col) {
	int delta_line = d_line - o_line;

	int d_column = int(d_col) - 65;
	int o_column = int(o_col) - 65;
	int delta_col = d_column - o_column;

	switch (delta_line) {
	case 1: {
		if ((delta_col == -1) || (delta_col == 0) || (delta_col == 1)) {
			
			game_state[o_line - 1][o_column].setPlayer(0);
			game_state[d_line - 1][d_column].setPlayer(2);
			return true;
		}
		else {
			//error
			//invalid column selection
			cout << "Error! You have selected an invalid column to move." << endl;
			return false;
		}
		break;
	}
	case 2: {
		if (delta_col == -2) {
			if (game_state[o_line][d_column + 1].getPlayer() == 2) {

				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(2);
				return true;
			}
			else if (game_state[o_line][d_column + 1].getPlayer() == 1) {

				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(2);
				game_state[o_line][d_column + 1].setPlayer(0);
				return true;
			}
			else {
				//error
				//not jumping over a piece
				cout << "Error! You're not jumping over a piece." << endl;
				return false;
			}
		}
		else if (delta_col == 0) {
			if (game_state[o_line][d_column].getPlayer() == 2) {

				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(2);
				return true;
			}
			else if (game_state[o_line][d_column].getPlayer() == 1) {

				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(2);
				game_state[o_line][d_column].setPlayer(0);
				return true;
			}
			else {
				//error
				//not jumping over a piece
				cout << "Error! You're not jumping over a piece." << endl;
				return false;
			}
		}
		else if (delta_col == 2) {
			if (game_state[o_line][d_column - 1].getPlayer() == 2) {

				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(2);
				return true;
			}
			else if (game_state[o_line][d_column - 1].getPlayer() == 1) {

				game_state[o_line - 1][o_column].setPlayer(0);
				game_state[d_line - 1][d_column].setPlayer(2);
				game_state[o_line][d_column - 1].setPlayer(0);
				return true;
			}
			else {
				//error
				//not jumping over a piece
				cout << "Error! You're not jumping over a piece." << endl;
				return false;
			}
		}
		else {
			//error
			//invalid column selection
			cout << "Error! You have selected an invalid column to move." << endl;
			return false;
		}
		break;
	}
	case 0: {
		if (delta_col == -2) {
			if (game_state[d_line - 1][d_column + 1].getPlayer() == 1) {

				game_state[d_line - 1][d_column].setPlayer(2);
				game_state[d_line - 1][d_column + 1].setPlayer(0);
				game_state[o_line - 1][o_column].setPlayer(0);
				return true;
			}
			else {
				//error
				//not capturing opponent's piece
				cout << "Error! You're not capturing opponent's piece" << endl;
				return false;
			}
		}
		else if (delta_col == 2) {
			if (game_state[d_line - 1][d_column - 1].getPlayer() == 1) {

				game_state[d_line - 1][d_column].setPlayer(2);
				game_state[d_line - 1][d_column - 1].setPlayer(0);
				game_state[o_line - 1][o_column].setPlayer(0);
				return true;
			}
			else {
				//error
				//not capturing opponent's piece
				cout << "Error! You're not capturing opponent's piece" << endl;
				return false;
			}
		}
		else {
			//error
			//invalid column selection
			cout << "Error! You have selected an invalid column to move." << endl;
			return false;
		}
		break;
	}
	default:
		//error
		//invalid line selection
		cout << "Error! You have selected an invalid line to move." << endl;
		return false;
		break;
	}
}




void Board::reach_endzone(int o_line, char o_col) {
	game_state[o_line - 1][(int)(o_col - 65)].setPlayer(0);
}




void Board::new_checkers_p1() {
	int counter = 0;
	int lines[14];
	int columns[14];
	int space1, space2;

	for (int i = 6; i < 8; i++) {
		for (int j = 1; j < 7; j++) {
			if (game_state[i][j].getPlayer() == 0) {
				lines[counter] = i;
				columns[counter] = j;
				counter++;
			}
		}
	}

	if (counter == 2) {
		game_state[lines[0]][columns[0]] = Piece(1);
		game_state[lines[1]][columns[1]] = Piece(1);
		cout << "Only 2 spaces available to drop pieces." << endl << "2 pieces were drop automatically!" << endl << endl;
	}
	else if (counter == 1) {
		game_state[lines[0]][columns[0]] = Piece(1);
		cout << "Only 1 space available to drop pieces." << endl << "1 piece was drop automatically!" << endl << endl;
	}
	else if (counter == 0) {
		cout << "No spaces available to drop pieces." << endl << "No piece was drop!" << endl << endl;
	}
	else {
		cout << "Spaces availables to drop:" << endl;
		for (int i = 0; i < counter; i++) {
			cout << i << " - [" << lines[i] << "," << (char)(columns[i]+65) << "]" << endl;
		}
		cout << endl << "Pick 2 spaces to drop 2 pieces" << endl;
		cin >> space1;
		cin >> space2;
		game_state[lines[space1]][columns[space1]] = Piece(1);
		game_state[lines[space2]][columns[space2]] = Piece(1);
		cout << endl << "Pieces dropped in the spaces you selected!" << endl << endl;
	}
}


void Board::new_checkers_p2() {
	int counter = 0;
	int lines[14];
	int columns[14];
	int space1, space2;

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 7; j++) {
			if (game_state[i][j].getPlayer() == 0) {
				lines[counter] = i;
				columns[counter] = j;
				counter++;
			}
		}
	}

	if (counter == 2) {
		game_state[lines[0]][columns[0]] = Piece(2);
		game_state[lines[1]][columns[1]] = Piece(2);
		cout << "Only 2 spaces available to drop pieces." << endl << "2 pieces were drop automatically!" << endl << endl;
	}
	else if (counter == 1) {
		game_state[lines[0]][columns[0]] = Piece(2);
		cout << "Only 1 space available to drop pieces." << endl << "1 piece was drop automatically!" << endl << endl;
	}
	else if (counter == 0) {
		cout << "No spaces available to drop pieces." << endl << "No piece was drop!" << endl;
	}
	else {
		cout << "Spaces availables to drop:" << endl;
		for (int i = 0; i < counter; i++) {
			cout << i << " - [" << lines[i] << "," << (char)(columns[i] + 65) << "]" << endl;
		}
		cout << endl << "Pick 2 spaces to drop 2 pieces" << endl;
		cin >> space1;
		cin >> space2;
		game_state[lines[space1]][columns[space1]] = Piece(2);
		game_state[lines[space2]][columns[space2]] = Piece(2);
		cout << endl << "Pieces dropped in the spaces you selected!" << endl << endl;
	}
}
