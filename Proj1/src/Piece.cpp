#include "Piece.h"

#include <iostream>
#include <iomanip>

using namespace std;

Piece::Piece(int player){
	this->player = player;
	setParameters();
}

Piece::Piece() {
	this->player = 0;
	setParameters();
}

Piece::~Piece() {

}

string Piece::getColor() {
	return color;
}


int Piece::getPlayer() {
	return player;
}

char Piece::getCharacter() {
	return character;
}

void Piece::setParameters() {
	if (player == 1) {
		character = 'X';
		color = "black";
	}
	else if (player == 2) {
		character = 'O';
		color = "white";
	}
	else {
		character = ' ';
		color = "";
	}
}
