#include "Graphics.h"

using namespace std;

void opening_menu() {
	cout << "WELCOME TO EXIMO" << endl << endl;
	cout << "1 - PvP" << endl;
	cout << "2 - PvC" << endl;
	cout << "3 - CvC" << endl;
	cout << "4 - LEAVE" << endl;
}

void center_string(char* s) {
	
	int l = strlen(s);
	int pos = (int)((80 - l) / 2);
	for (int i = 0; i < pos; i++) {
		cout << " ";
	}

	cout << s << endl;
}



