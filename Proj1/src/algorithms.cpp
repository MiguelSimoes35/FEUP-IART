#include "algorithms.h"

using namespace std;

Node* newNode(int value, int depth, int ol, char oc, int dl, char dc) {

	Node* tmp = new Node;
	tmp->value = value;
	tmp->depth = depth;
	tmp->o_lin = ol;
	tmp->o_col = oc;
	tmp->d_lin = dl;
	tmp->d_col = dc;
	return tmp;

}

int minimax(Node* root, int depth, bool maximizingPlayer) {

	//cout << root->value << endl;
	
	if (depth == 0) {
		return root->value;
	}

	if (maximizingPlayer) {
		int maxVal = -1000;
		for (unsigned int i = 0; i < root->children.size(); i++) {
			int val = minimax(root->children.at(i), (depth - 1), false);
			//cout << "max val " << maxVal << endl;
			//cout << "val " << val << endl;
			
			maxVal = max(maxVal, val);

			//cout << "max val " << maxVal << endl;
			//cout << "max val " << maxVal << endl;
		}
		
		return maxVal;
	}
	else {
		int minVal = 1000;
		for (unsigned int i = 0; i < root->children.size(); i++) {
			int val = minimax(root->children.at(i), (depth - 1), true);
			minVal = min(minVal, val);
			//cout << "min val: " << minVal << endl;
		}

		return minVal;
	}
	
	
	
	return 0;
}

int minimaxAB(Node* root, int depth, int alpha, int beta, bool maximizingPlayer) {

	if (depth == 0) {
		return root->value;
	}

	if (maximizingPlayer) {
		int maxVal = -1000;
		for (unsigned int i = 0; i < root->children.size(); i++) {
			int val = minimaxAB(root->children.at(i), (depth - 1), alpha, beta, false);
			maxVal = max(maxVal, val);
			alpha = max(alpha, val);
			if (beta <= alpha) {
				//cout << "pruning occurred ALPHA(" << alpha << ")" << " BETA(" << beta << ")" << endl;
				break;
			}
		}
		return maxVal;
	}
	else {
		int minVal = 1000;
		for (unsigned int i = 0; i < root->children.size(); i++) {
			int val = minimaxAB(root->children.at(i), (depth - 1), alpha, beta, true);
			minVal = min(minVal, val);
			beta = min(beta, val);
			if (beta <= alpha) {
				//cout << "pruning occurred ALPHA(" << alpha << ")" << " BETA(" << beta << ")" << endl;
				break;
			}
		}
		return minVal;
	}



}



