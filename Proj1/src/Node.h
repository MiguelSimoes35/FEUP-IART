#pragma once

#include <vector>

using namespace std;

struct Node
{
	int value;
	int depth;
	vector<Node*> children;

};

