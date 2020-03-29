#pragma once

#include "Node.h"
#include "Board.h"

#include <algorithm>
#include <iostream>

Node* newNode(int value, int depth, int ol, char oc, int dl, char dc);

int minimax(Node* root, int depth, bool maximizingPlayer);

int minimaxAB(Node* root, int depth, int alpha, int beta, bool maximizingPlayer);



