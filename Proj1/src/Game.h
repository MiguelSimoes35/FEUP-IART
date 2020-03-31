#pragma once

#include "Board.h"
#include "Player.h"
#include "Graphics.h"

using namespace std;

class Game {
	Board board;
	Player player1;
	Player player2;
public:
	Game();
	void start();
	void pvp();
	void pvc1();
	void pvc2();
	void pvc3();
	void cvc();
};