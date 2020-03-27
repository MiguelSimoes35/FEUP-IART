#include "Game.h"

Game::Game(){

}

void Game::start() {
	Board b = Board();
	b.display_board();
	int pieces_player1 = b.count_p1_pieces();
	int pieces_player2 = b.count_p2_pieces();

	cout << "Player 1 pieces: " << pieces_player1 << endl;
	cout << "Player 2 pieces: " << pieces_player2 << endl << endl << endl;

}

void Game::pvp() {

}
