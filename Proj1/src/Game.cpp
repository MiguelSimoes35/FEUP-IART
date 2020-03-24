#include "Game.h"

Game::Game(){

}

void Game::start() {
	Board b = Board();
	b.display_board();
	b.count_p1_pieces();
}
