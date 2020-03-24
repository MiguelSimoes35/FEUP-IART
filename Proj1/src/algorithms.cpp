#include "algorithms.h"

using namespace std;

Node* newNode(int value, int depth) {

	Node* tmp = new Node;
	tmp->value = value;
	tmp->depth = depth;
	
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




