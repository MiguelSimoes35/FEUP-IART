#include <iostream>

#include "Game.h"

using namespace std;

int main() {
	Game game;

	opening_menu();
	int mode = start_menu();
	game.start(mode);

	system("pause");

	return 0;
}
