#include "Board.h"



Board::Board()
{
	
}

void Board::fillBoard() {
	for (int line = 0; line < 8; line++) {
		for (int col = 0; col < 8; col++) {
			switch (line)
			{
			case 0: if (col == 0 || col == 7) {
				game_state[line][col] = EMPTY;
			}
					else {
				game_state[line][col] = PLAYER2;
			}
					break;
			case 1: if (col == 0 || col == 7) {
				game_state[line][col] = EMPTY;
			}
					else {
				game_state[line][col] = PLAYER2;
			}
					break;
			case 2: if (col == 0 || col == 3 || col == 4 || col == 7) {
				game_state[line][col] = EMPTY;
			}
					else {
				game_state[line][col] = PLAYER2;
			}
					break;
			case 5: if (col == 0 || col == 3 || col == 4 || col == 7) {
				game_state[line][col] = EMPTY;
			}
					else {
				game_state[line][col] = PLAYER1;
			}
					break;
			case 6: if (col == 0 || col == 7) {
				game_state[line][col] = EMPTY;
			}
					else {
				game_state[line][col] = PLAYER1;
			}
					break;
			case 7: if (col == 0 || col == 7) {
				game_state[line][col] = EMPTY;
			}
					else {
				game_state[line][col] = PLAYER1;
			}
					break;
			default:
				game_state[line][col] = EMPTY;
				break;
			}
		}
	}
}


