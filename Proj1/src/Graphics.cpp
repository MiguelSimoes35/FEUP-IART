#include "Graphics.h"

#undef max

using namespace std;

void opening_menu() {
	cout << "                                             " << endl;
	cout << "          _______  __ ______  _________      " << endl;
	cout << "         / ____/ |/ //  _/  |/  / __  /      " << endl;
	cout << "        / __/  |   / / // /|_/ / / / /       " << endl;
	cout << "       / /___ /   /_/ // /  / / /_/ /        " << endl;
	cout << "      /_____//_/|_/___/_/  /_/_____/         " << endl;
	cout << "                                             " << endl;
	cout << "                                             " << endl;
	cout << "                                             " << endl;
	system("pause");
	system("CLS");
}

int start_menu() {
	
	int option;
	
	cout << " ___________________________________________ " << endl;
	cout << "|                                           |" << endl;
	cout << "|                  WELCOME                  |" << endl;
	cout << "|                                           |" << endl;
	cout << "|      1 - PvP                              |" << endl;
	cout << "|      2 - PvC                              |" << endl;
	cout << "|      3 - CvC                              |" << endl;
	cout << "|      4 - LEAVE                            |" << endl;
	cout << "|___________________________________________|" << endl << endl;

	cout << "Option-> ";
	cin >> option;

	while (true) {
		if (cin.fail() || option > 4 || option < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid option" << endl;
			cout << "Option-> ";
			cin >> option;
		}
		else if (!cin.fail()) {
			break;
		}
	}

	if (option == 1) {
		system("CLS");
		return 1;
	}
	else if (option == 2) {
		system("CLS");
		return 2;
	}
	else if (option == 3) {
		system("CLS");
		return 3;
	}
	else {
		exit(1);
	}
}

void end_menu(int winner) {
	int option;

	cout << " ___________________________________________ " << endl;
	cout << "|                                           |" << endl;
	cout << "|                GAME OVER                  |" << endl;
	cout << "|          Player " << winner << " won the game!           |" << endl;
	cout << "|                                           |" << endl;
	cout << "|      1 - Initial menu                     |" << endl;
	cout << "|      2 - Quit                             |" << endl;
	cout << "|                                           |" << endl;
	cout << "|___________________________________________|" << endl << endl;

	cout << "Option-> ";
	cin >> option;

	while (true) {
		if (cin.fail() || option > 2 || option < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid option" << endl;
			cout << "Option-> ";
			cin >> option;
		}
		else if (!cin.fail()) {
			break;
		}
	}

	if (option == 1) {
		system("CLS");
		start_menu();
	}
	else {
		exit(1);
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
