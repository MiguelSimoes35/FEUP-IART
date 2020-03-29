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
			cout << i << " - [" << lines[i] << "," << (char)(columns[i] + 65) << "]" << endl;
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

int Board::evalGameState(bool player1) {

	int ret = 0;

	if (player1) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (game_state[i][j].getPlayer() == 1) {
					ret += 5;
					ret += (8 - i);
				}
				else if(game_state[i][j].getPlayer() == 2){
					ret -= 5;
					ret -= (i + 1);
				}
			}
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (game_state[i][j].getPlayer() == 2) {
					ret += 5;
					ret += (i + 1);
				}
				else if (game_state[i][j].getPlayer() == 1) {
					ret -= 5;
					ret -= (8 - i);
				}
			}
		}
	}
	

	return ret;
}

void Board::generateTree(bool player1) {
	Node* root = newNode(NULL, 2, 0, 0, 0, 0);

	Board tmpBoard;
	tmpBoard = *this;

	int child = 0;

	if (player1) {
		//first play - computer's play
		for (int firstpl = 0; firstpl < 8; firstpl++) {
			for (int firstpc = 0; firstpc < 8; firstpc++) {
				if (tmpBoard.getCell(firstpl, firstpc).getPlayer() == 1) {
					for (int aux1l = 0; aux1l < 8; aux1l++) {
						for (int aux1c = 0; aux1c < 8; aux1c++) {
							if (tmpBoard.check_free(aux1l +1, colToChar(aux1c)) && tmpBoard.can_move_player1(firstpl + 1, colToChar(firstpc), aux1l + 1, colToChar(aux1c))) {
								tmpBoard.move_player1(firstpl + 1, colToChar(firstpc), aux1l + 1, colToChar(aux1c));
								if (aux1l == 0) {
									tmpBoard.reach_endzone((aux1l + 1), colToChar(aux1c));
									tmpBoard.new_checkers_c1();
								}
								root->children.push_back(newNode(NULL, 1, firstpl + 1, colToChar(firstpc), aux1l + 1, colToChar(aux1c)));
								//second play - adv's play
								for (int secondpl = 0; secondpl < 8; secondpl++) {
									for (int secondpc = 0; secondpc < 8; secondpc++) {
										if (tmpBoard.getCell(secondpl, secondpc).getPlayer() == 2) {
											for (int aux2l = 0; aux2l < 8; aux2l++) {
												for (int aux2c = 0; aux2c < 8; aux2c++) {
													if (tmpBoard.check_free(aux2l + 1, colToChar(aux2c)) && tmpBoard.can_move_player1(secondpl + 1, colToChar(secondpc), aux2l + 1, colToChar(aux2c))) {
														tmpBoard.move_player1(secondpl + 1, colToChar(secondpc), aux2l + 1, colToChar(aux2c));
														if (aux2l == 7) {
															tmpBoard.reach_endzone((aux2l + 1), colToChar(aux2c));
															tmpBoard.new_checkers_c2();
														}
														root->children.at(child)->children.push_back(newNode(tmpBoard.evalGameState(true), 0, secondpl + 1, colToChar(secondpc), aux2l + 1, colToChar(aux2c)));
													}
												}
											}
										}
									}
								}

								tmpBoard = *this;
								child++;
							}
						}
					}
				}
			}
		}

		//appplying minimax to the generated tree
		int choice = minimaxAB(root, 2, -1000, 1000, true);
		int chosen_child;
		for (int i = 0; i < root->children.size(); i++) {
			for (int j = 0; j < root->children.at(i)->children.size(); j++) {				
				if (root->children.at(i)->children.at(j)->value == choice) {
					chosen_child = i;
				}				
			}
		}

		//realizing the play
		move_player1(root->children.at(chosen_child)->o_lin,
			root->children.at(chosen_child)->o_col,
			root->children.at(chosen_child)->d_lin,
			root->children.at(chosen_child)->d_col);
		if (root->children.at(chosen_child)->d_lin == 1) {
			reach_endzone(root->children.at(chosen_child)->d_lin, root->children.at(chosen_child)->d_col);
			new_checkers_c1();
		}

	}
	else {
		//first play - computer's play
		for (int firstpl = 0; firstpl < 8; firstpl++) {
			for (int firstpc = 0; firstpc < 8; firstpc++) {
				if (tmpBoard.getCell(firstpl, firstpc).getPlayer() == 2) {
					for (int aux1l = 0; aux1l < 8; aux1l++) {
						for (int aux1c = 0; aux1c < 8; aux1c++) {
							if (tmpBoard.check_free(aux1l + 1, colToChar(aux1c)) && tmpBoard.can_move_player2(firstpl + 1, colToChar(firstpc), aux1l + 1, colToChar(aux1c))) {
								tmpBoard.move_player2(firstpl + 1, colToChar(firstpc), aux1l + 1, colToChar(aux1c));
								if (aux1l == 7) {
									tmpBoard.reach_endzone((aux1l + 1), colToChar(aux1c));
									tmpBoard.new_checkers_c2();
								}
								root->children.push_back(newNode(NULL, 1, firstpl + 1, colToChar(firstpc), aux1l + 1, colToChar(aux1c)));
								//second play - adv's play
								for (int secondpl = 0; secondpl < 8; secondpl++) {
									for (int secondpc = 0; secondpc < 8; secondpc++) {
										if (tmpBoard.getCell(secondpl, secondpc).getPlayer() == 1) {
											for (int aux2l = 0; aux2l < 8; aux2l++) {
												for (int aux2c = 0; aux2c < 8; aux2c++) {
													if (tmpBoard.check_free(aux2l + 1, colToChar(aux2c)) && tmpBoard.can_move_player2(secondpl + 1, colToChar(secondpc), aux2l + 1, colToChar(aux2c))) {
														tmpBoard.move_player2(secondpl + 1, colToChar(secondpc), aux2l + 1, colToChar(aux2c));
														if (aux2l == 0) {
															tmpBoard.reach_endzone((aux2l + 1), colToChar(aux2c));
															tmpBoard.new_checkers_c1();
														}
														root->children.at(child)->children.push_back(newNode(tmpBoard.evalGameState(false), 0, secondpl + 1, colToChar(secondpc), aux2l + 1, colToChar(aux2c)));
													}
												}
											}
										}
									}
								}

								tmpBoard = *this;
								child++;
							}
						}
					}
				}
			}
		}

		//appplying minimax to the generated tree
		int choice = minimaxAB(root, 2, -1000, 1000, true);
		int chosen_child;
		for (int i = 0; i < root->children.size(); i++) {
			for (int j = 0; j < root->children.at(i)->children.size(); j++) {
				if (root->children.at(i)->children.at(j)->value == choice) {
					chosen_child = i;
				}
			}
		}

		//realizing the play
		move_player2(root->children.at(chosen_child)->o_lin,
			root->children.at(chosen_child)->o_col,
			root->children.at(chosen_child)->d_lin,
			root->children.at(chosen_child)->d_col);

		if (root->children.at(chosen_child)->d_lin == 8) {
			reach_endzone(root->children.at(chosen_child)->d_lin, root->children.at(chosen_child)->d_col);
			new_checkers_c2();
		}
	}
}

char Board::colToChar(int col) {
	switch (col)
	{
	case 0: return 'A';
	case 1: return 'B';
	case 2: return 'C';
	case 3: return 'D';
	case 4: return 'E';
	case 5: return 'F';
	case 6: return 'G';
	case 7: return 'H';
	default:
		//something went wrong
		break;
	}
}


bool Board::can_move_player1(int o_line, char o_col, int d_line, char d_col) {
	int delta_line = d_line - o_line;

	int d_column = int(d_col) - 65;
	int o_column = int(o_col) - 65;
	int delta_col = d_column - o_column;

	switch (delta_line) {
	case -1: {
		if ((delta_col == -1) || (delta_col == 0) || (delta_col == 1)) {
			return true;
		}
		else {
			//error
			//invalid column selection
			return false;
		}
		break;
	}
	case -2: {
		if (delta_col == -2) {
			if (game_state[d_line][d_column + 1].getPlayer() == 1) {
				return true;
			}
			else if (game_state[d_line][d_column + 1].getPlayer() == 2) {
				return true;
			}
			else {
				//error
				//not jumping over a piece
				return false;
			}
		}
		else if (delta_col == 0) {
			if (game_state[d_line][d_column].getPlayer() == 1) {
				return true;
			}
			else if (game_state[d_line][d_column].getPlayer() == 2) {
				return true;
			}
			else {
				//error
				//not jumping over a piece
				return false;
			}
		}
		else if (delta_col == 2) {
			if (game_state[d_line][d_column - 1].getPlayer() == 1) {
				return true;
			}
			else if (game_state[d_line][d_column - 1].getPlayer() == 2) {
				return true;
			}
			else {
				//error
				//not jumping over a piece
				return false;
			}
		}
		else {
			//error
			//invalid column selection
			return false;
		}
		break;
	}
	case 0: {
		if (delta_col == -2) {
			if (game_state[d_line - 1][d_column + 1].getPlayer() == 2) {
				return true;
			}
			else {
				//error
				//not capturing opponent's piece
				return false;
			}
		}
		else if (delta_col == 2) {
			if (game_state[d_line - 1][d_column - 1].getPlayer() == 2) {
				return true;
			}
			else {
				//error
				//not capturing opponent's piece
				return false;
			}
		}
		else {
			//error
			//invalid column selection
			return false;
		}
		break;
	}
	default:
		//error
		//invalid line selection
		return false;
		break;
	}
}

Piece Board::getCell(int line, int col) {
	return game_state[line][col];
}

bool Board::can_move_player2(int o_line, char o_col, int d_line, char d_col) {
	int delta_line = d_line - o_line;

	int d_column = int(d_col) - 65;
	int o_column = int(o_col) - 65;
	int delta_col = d_column - o_column;

	switch (delta_line) {
	case 1: {
		if ((delta_col == -1) || (delta_col == 0) || (delta_col == 1)) {
			return true;
		}
		else {
			return false;
		}
		break;
	}
	case 2: {
		if (delta_col == -2) {
			if (game_state[o_line][d_column + 1].getPlayer() == 2) {
				return true;
			}
			else if (game_state[o_line][d_column + 1].getPlayer() == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (delta_col == 0) {
			if (game_state[o_line][d_column].getPlayer() == 2) {
				return true;
			}
			else if (game_state[o_line][d_column].getPlayer() == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (delta_col == 2) {
			if (game_state[o_line][d_column - 1].getPlayer() == 2) {
				return true;
			}
			else if (game_state[o_line][d_column - 1].getPlayer() == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	}
	case 0: {
		if (delta_col == -2) {
			if (game_state[d_line - 1][d_column + 1].getPlayer() == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (delta_col == 2) {
			if (game_state[d_line - 1][d_column - 1].getPlayer() == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	}
	default:
		return false;
		break;
	}
}

void Board::new_checkers_c1() {
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
		game_state[lines[0]][columns[0]] = Piece(1);
		game_state[lines[1]][columns[1]] = Piece(1);
		cout << "2 pieces were drop automatically!" << endl << endl;
	}
}


void Board::new_checkers_c2() {
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
		game_state[lines[0]][columns[0]] = Piece(2);
		game_state[lines[1]][columns[1]] = Piece(2);
		cout << "2 pieces were drop automatically!" << endl << endl;
	}
}
