#include "Graphics.h"

#undef max

using namespace std;

void opening_menu() {
	
	int option;
	
	cout  << "WELCOME" << endl << endl;
	cout << "1 - PvP" << endl;
	cout << "2 - PvC" << endl;
	cout << "3 - CvC" << endl;
	cout << "4 - LEAVE" << endl;

	cout << "-> ";
	cin >> option;

	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid option" << endl;
			cout << "-> ";
			cin >> option;
		}
		
		if (!cin.fail()) {
			break;
		}
	}



}

void center_string(char* s) {
	
	int l = strlen(s);
	int pos = (int)((80 - l) / 2);
	for (int i = 0; i < pos; i++) {
		cout << " ";
	}

	cout << s << endl;
}

int getCols() {

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int ret;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	ret = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	return ret;
}

void print_centered(std::string s) {


	cout << setw(60) << s << endl;



}

