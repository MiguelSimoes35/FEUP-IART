#pragma once

#include <string>

using namespace std;

class Piece {
	string color;
	int player;
	char character;
	bool isUp;
public:
	Piece(int player);
	Piece();
	~Piece();
	string getColor();
	int getPlayer();
	void setPlayer(int player);
	char getCharacter();
	void setParameters();
};
