#include "Game.h"

#undef max

Game::Game(){

}

void Game::start(int option) {
	if (option == 1) {
		pvp();
	}
	else if (option == 2) {

	}
	else if (option == 3) {

	}
	else {

	}
}

void Game::pvp() {
	Board b = Board();
	b.display_board();
	cout << "Player 1 has the X" << endl << "Player 2 has the O" << endl << endl << "Player 1 starts!" << endl;
	cout << "You will select your moves by steps!" << endl;
	while (true) {
		int p1_oline, p1_destline, p2_oline, p2_destline;
		char p1_ocol, p1_destcol, p2_ocol, p2_destcol; 

		while (true) {
			cout << endl << "Player 1 turn..." << endl;
			do {
				cout << endl << "Origin coordinates (hint: line of your piece (space) column of your piece): ";
				cin >> p1_oline;
				cin >> p1_ocol;
				while (true) {
					if (cin.fail() || p1_oline < 1 || p1_oline > 8 || (int) p1_ocol < 65 || (int) p1_ocol > 72) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Please enter valid origin coordinates." << endl;
						cout << endl << "Origin coordinates:";
						cin >> p1_oline;
						cin >> p1_ocol;
					}
					else if (!cin.fail()) {
						break;
					}
				}
			} while (!b.check_piece1(p1_oline, p1_ocol));

			do {
				cout << endl << "Destiny coordinates (hint: line of your piece (space) column of your piece): ";
				cin >> p1_destline;
				cin >> p1_destcol;
				while (true) {
					if (cin.fail() || p1_destline < 1 || p1_destline > 8 || (int)p1_destcol < 65 || (int)p1_destcol > 72) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Please enter valid destiny coordinates." << endl;
						cout << endl << "Destiny coordinates:";
						cin >> p1_destline;
						cin >> p1_destcol;
					}
					else if (!cin.fail()) {
						break;
					}
				}
			} while (!b.check_free(p1_destline, p1_destcol));

			if (b.move_player1(p1_oline, p1_ocol, p1_destline, p1_destcol) == true) {
				cout << endl;
				b.display_board();
				if (p1_destline == 1) {
					cout << endl << endl << "Your piece reached the end of the board, it will be removed and you can add 2 more in your drop zone if you have space." << endl;
					b.reach_endzone(p1_destline, p1_destcol);
					b.new_checkers_p1();
					b.display_board();
				}
				break;
			}
			else {
				cout << endl << "Repeat your origin and destination coordinates again!" << endl << endl;
				b.display_board();
			}
		}

		if (b.count_p2_pieces() == 0) {
			system("CLS");
			end_menu(1);
			break;
		}

		while (true) {
			cout << endl << "Player 2 turn..." << endl;
			do {
				cout << endl << "Origin coordinates (hint: line of your piece (space) column of your piece): ";
				cin >> p2_oline;
				cin >> p2_ocol;
				while (true) {
					if (cin.fail() || p2_oline < 1 || p2_oline > 8 || (int)p2_ocol < 65 || (int)p2_ocol > 72) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Please enter valid origin coordinates." << endl;
						cout << endl << "Origin coordinates:";
						cin >> p2_oline;
						cin >> p2_ocol;
					}
					else if (!cin.fail()) {
						break;
					}
				}
			} while (!b.check_piece2(p2_oline, p2_ocol));

			do {
				cout << endl << "Destiny coordinates (hint: line of your piece (space) column of your piece): ";
				cin >> p2_destline;
				cin >> p2_destcol;
				while (true) {
					if (cin.fail() || p2_destline < 1 || p2_destline > 8 || (int)p2_destcol < 65 || (int)p2_destcol > 72) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Please enter valid destiny coordinates." << endl;
						cout << endl << "Destiny coordinates:";
						cin >> p2_destline;
						cin >> p2_destcol;
					}
					else if (!cin.fail()) {
						break;
					}
				}
			} while (!b.check_free(p2_destline, p2_destcol));

			if (b.move_player2(p2_oline, p2_ocol, p2_destline, p2_destcol) == true) {
				cout << endl;
				b.display_board();
				if (p2_destline == 8) {
					cout << "Your piece reached the end of the board, it will be removed and you can add 2 more in your drop zone if you have space." << endl;
					b.reach_endzone(p2_destline, p2_destcol);
					b.new_checkers_p2();
					b.display_board();
				}
				break;
			}
			else {
				cout << "Repeat your origin and destination coordinates again!" << endl << endl;
				b.display_board();
			}
		}

		if (b.count_p1_pieces() == 0) {
			system("CLS");
			end_menu(2);
			break;
		}
	}
}
