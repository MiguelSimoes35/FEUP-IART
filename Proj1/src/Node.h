#pragma once

#include <vector>

using namespace std;

struct Node
{
	int value;
	int depth;
	vector<Node*> children;

	int o_lin, o_col, d_lin, d_col;

};

