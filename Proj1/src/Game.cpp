#include "Game.h"
#undef max
Game::Game() {

}

void Game::start() {
	cvc();
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
				cout << "Origin coordinates (hint: line of your piece (space) column of your piece): ";
				cin >> p1_oline;
				cin >> p1_ocol;
			} while (!b.check_piece1(p1_oline, p1_ocol));

			do {
				cout << "Destiny coordinates (hint: line of your piece (space) column of your piece): ";
				cin >> p1_destline;
				cin >> p1_destcol;
			} while (!b.check_free(p1_destline, p1_destcol));

			if (b.move_player1(p1_oline, p1_ocol, p1_destline, p1_destcol) == true) {
				b.display_board();
				if (p1_destline == 1) {
					cout << endl << "Your piece reached the end of the board, it will be removed and you can add 2 more in your drop zone if you have space." << endl;
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

		if (b.count_p1_pieces() == 0) {
			cout << endl << "HE HAVE A WINNER: Player 1 won the game!" << endl;
			break;
		}

		while (true) {
			cout << endl << "Player 2 turn..." << endl;
			do {
				cout << "Origin coordinates (hint: line of your piece (space) column of your piece): ";
				cin >> p2_oline;
				cin >> p2_ocol;
			} while (!b.check_piece2(p2_oline, p2_ocol));

			do {
				cout << "Destiny coordinates (hint: line of your piece (space) column of your piece): ";
				cin >> p2_destline;
				cin >> p2_destcol;
			} while (!b.check_free(p2_destline, p2_destcol));

			if (b.move_player2(p2_oline, p2_ocol, p2_destline, p2_destcol) == true) {
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

		if (b.count_p2_pieces() == 0) {
			cout << endl << "HE HAVE A WINNER: Player 2 won the game!" << endl;
			break;
		}
	}
}

void Game::pvc1() {

	cout << "Choose difficulty" << endl;
	cout << "1 - Recruit" << endl;
	cout << "2 - Hardened" << endl;
	cout << "3 - Veteran" << endl;
	int diff;
	cout << "-> ";
	cin >> diff;
	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid option" << endl;
			cout << "-> ";
			cin >> diff;
		}

		if (!cin.fail()) {
			break;
		}
	}
	
	switch (diff)
	{
	case 1: 
		break;
	case 2: pvc2();
		break;
	case 3: pvc3();
		break;
	default:
		cout << "Unexpected error happened" << endl;
		break;
	}


	Board b = Board();
	b.display_board();
	cout << "Do you wish to be the starting player?" << endl;
	cout << "        1 - YES     2 - NO" << endl;
	int player1;
	cout << "-> ";
	cin >> player1;
	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid option" << endl;
			cout << "-> ";
			cin >> player1;
		}

		if (!cin.fail()) {
			break;
		}
	}
	cout << "Player 1 has the X" << endl << "Computer has the O" << endl << endl << "Player 1 starts!" << endl;
	cout << "You will select your moves by steps!" << endl;
	if (player1 == 2) {
		while (true) {
			int p1_oline, p1_destline, p2_oline, p2_destline;
			char p1_ocol, p1_destcol, p2_ocol, p2_destcol;

			
			b.generateTree_d1(true);
			b.display_board();
				

			if (b.count_p1_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 1 won the game!" << endl;
				break;
			}

			while (true) {
				cout << endl << "Your turn..." << endl;
			do {
				cout << "Origin coordinates (hint: line of your piece (space) column of your piece): ";
				cin >> p2_oline;
				cin >> p2_ocol;
			} while (!b.check_piece2(p2_oline, p2_ocol));

			do {
				cout << "Destiny coordinates (hint: line of your piece (space) column of your piece): ";
				cin >> p2_destline;
				cin >> p2_destcol;
			} while (!b.check_free(p2_destline, p2_destcol));

			if (b.move_player2(p2_oline, p2_ocol, p2_destline, p2_destcol) == true) {
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

			if (b.count_p2_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 2 won the game!" << endl;
				break;
			}
		}
	}
	else {
		while (true) {
			int p1_oline, p1_destline, p2_oline, p2_destline;
			char p1_ocol, p1_destcol, p2_ocol, p2_destcol;

			while (true) {
				cout << endl << "Your turn..." << endl;
				do {
					cout << "Origin coordinates (hint: line of your piece (space) column of your piece): ";
					cin >> p1_oline;
					cin >> p1_ocol;
				} while (!b.check_piece1(p1_oline, p1_ocol));

				do {
					cout << "Destiny coordinates (hint: line of your piece (space) column of your piece): ";
					cin >> p1_destline;
					cin >> p1_destcol;
				} while (!b.check_free(p1_destline, p1_destcol));

				if (b.move_player1(p1_oline, p1_ocol, p1_destline, p1_destcol) == true) {
					b.display_board();
					if (p1_destline == 1) {
						cout << endl << "Your piece reached the end of the board, it will be removed and you can add 2 more in your drop zone if you have space." << endl;
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

			if (b.count_p1_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 1 won the game!" << endl;
				break;
			}

			b.generateTree_d1(false);
			b.display_board();				

			if (b.count_p2_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 2 won the game!" << endl;
				break;
			}
		}
	}
	

}

void Game::pvc2() {
	Board b = Board();
	b.display_board();
	cout << "Do you wish to be the starting player?" << endl;
	cout << "        1 - YES     2 - NO" << endl;
	int player1;
	cout << "-> ";
	cin >> player1;
	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid option" << endl;
			cout << "-> ";
			cin >> player1;
		}

		if (!cin.fail()) {
			break;
		}
	}
	cout << "Player 1 has the X" << endl << "Computer has the O" << endl << endl << "Player 1 starts!" << endl;
	cout << "You will select your moves by steps!" << endl;
	if (player1 == 2) {
		while (true) {
			int p1_oline, p1_destline, p2_oline, p2_destline;
			char p1_ocol, p1_destcol, p2_ocol, p2_destcol;


			b.generateTree_d2(true);
			b.display_board();


			if (b.count_p1_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 1 won the game!" << endl;
				break;
			}

			while (true) {
				cout << endl << "Your turn..." << endl;
				do {
					cout << "Origin coordinates (hint: line of your piece (space) column of your piece): ";
					cin >> p2_oline;
					cin >> p2_ocol;
				} while (!b.check_piece2(p2_oline, p2_ocol));

				do {
					cout << "Destiny coordinates (hint: line of your piece (space) column of your piece): ";
					cin >> p2_destline;
					cin >> p2_destcol;
				} while (!b.check_free(p2_destline, p2_destcol));

				if (b.move_player2(p2_oline, p2_ocol, p2_destline, p2_destcol) == true) {
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

			if (b.count_p2_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 2 won the game!" << endl;
				break;
			}
		}
	}
	else {
		while (true) {
			int p1_oline, p1_destline, p2_oline, p2_destline;
			char p1_ocol, p1_destcol, p2_ocol, p2_destcol;

			while (true) {
				cout << endl << "Your turn..." << endl;
				do {
					cout << "Origin coordinates (hint: line of your piece (space) column of your piece): ";
					cin >> p1_oline;
					cin >> p1_ocol;
				} while (!b.check_piece1(p1_oline, p1_ocol));

				do {
					cout << "Destiny coordinates (hint: line of your piece (space) column of your piece): ";
					cin >> p1_destline;
					cin >> p1_destcol;
				} while (!b.check_free(p1_destline, p1_destcol));

				if (b.move_player1(p1_oline, p1_ocol, p1_destline, p1_destcol) == true) {
					b.display_board();
					if (p1_destline == 1) {
						cout << endl << "Your piece reached the end of the board, it will be removed and you can add 2 more in your drop zone if you have space." << endl;
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

			if (b.count_p1_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 1 won the game!" << endl;
				break;
			}

			b.generateTree(false);
			b.display_board();

			if (b.count_p2_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 2 won the game!" << endl;
				break;
			}
		}
	}


}

void Game::pvc3() {

	
	Board b = Board();
	b.display_board();
	cout << "Do you wish to be the starting player?" << endl;
	cout << "        1 - YES     2 - NO" << endl;
	int player1;
	cout << "-> ";
	cin >> player1;
	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid option" << endl;
			cout << "-> ";
			cin >> player1;
		}

		if (!cin.fail()) {
			break;
		}
	}
	cout << "Player 1 has the X" << endl << "Computer has the O" << endl << endl << "Player 1 starts!" << endl;
	cout << "You will select your moves by steps!" << endl;
	if (player1 == 2) {
		while (true) {
			int p1_oline, p1_destline, p2_oline, p2_destline;
			char p1_ocol, p1_destcol, p2_ocol, p2_destcol;


			b.generateTree(true);
			b.display_board();


			if (b.count_p1_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 1 won the game!" << endl;
				break;
			}

			while (true) {
				cout << endl << "Your turn..." << endl;
				do {
					cout << "Origin coordinates (hint: line of your piece (space) column of your piece): ";
					cin >> p2_oline;
					cin >> p2_ocol;
				} while (!b.check_piece2(p2_oline, p2_ocol));

				do {
					cout << "Destiny coordinates (hint: line of your piece (space) column of your piece): ";
					cin >> p2_destline;
					cin >> p2_destcol;
				} while (!b.check_free(p2_destline, p2_destcol));

				if (b.move_player2(p2_oline, p2_ocol, p2_destline, p2_destcol) == true) {
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

			if (b.count_p2_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 2 won the game!" << endl;
				break;
			}
		}
	}
	else {
		while (true) {
			int p1_oline, p1_destline, p2_oline, p2_destline;
			char p1_ocol, p1_destcol, p2_ocol, p2_destcol;

			while (true) {
				cout << endl << "Your turn..." << endl;
				do {
					cout << "Origin coordinates (hint: line of your piece (space) column of your piece): ";
					cin >> p1_oline;
					cin >> p1_ocol;
				} while (!b.check_piece1(p1_oline, p1_ocol));

				do {
					cout << "Destiny coordinates (hint: line of your piece (space) column of your piece): ";
					cin >> p1_destline;
					cin >> p1_destcol;
				} while (!b.check_free(p1_destline, p1_destcol));

				if (b.move_player1(p1_oline, p1_ocol, p1_destline, p1_destcol) == true) {
					b.display_board();
					if (p1_destline == 1) {
						cout << endl << "Your piece reached the end of the board, it will be removed and you can add 2 more in your drop zone if you have space." << endl;
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

			if (b.count_p1_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 1 won the game!" << endl;
				break;
			}

			b.generateTree(false);
			b.display_board();

			if (b.count_p2_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 2 won the game!" << endl;
				break;
			}
		}
	}


}

void Game::cvc() {
	Board b = Board();
	b.display_board();
	cout << "Player 1 has the X" << endl << "Computer has the O" << endl << endl << "Player 1 starts!" << endl;
	cout << "You will select your moves by steps!" << endl;
		while (true) {
			int p1_oline, p1_destline, p2_oline, p2_destline;
			char p1_ocol, p1_destcol, p2_ocol, p2_destcol;


			b.generateTree_d2(true);
			system("cls");
			b.display_board();


			if (b.count_p1_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 1 won the game!" << endl;
				break;
			}
			b.generateTree_d1(false);
			system("cls");
			b.display_board();

			if (b.count_p2_pieces() == 0) {
				cout << endl << "HE HAVE A WINNER: Player 2 won the game!" << endl;
				break;
			}
		}
	
	
		
	
}

