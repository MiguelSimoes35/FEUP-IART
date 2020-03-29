#include "Game.h"

Game::Game() {

}

void Game::start() {
	pvc();
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

void Game::pvc() {
	
	Board b = Board();
	cout << "Game state evaluation " << b.evalGameState(true) << endl;
	b.display_board();
	cout << "Player 1 has the X" << endl << "Computer has the O" << endl << endl << "Player 1 starts!" << endl;
	cout << "You will select your moves by steps!" << endl;
	while (true) {
		int p1_oline, p1_destline, p2_oline, p2_destline;
		char p1_ocol, p1_destcol, p2_ocol, p2_destcol;

		//while (true) {
			cout << endl << "Player 1 turn..." << endl;
			b.generateTree(true);
			b.display_board();
			/*do {
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
			}*/
		//}

		if (b.count_p1_pieces() == 0) {
			cout << endl << "HE HAVE A WINNER: Player 1 won the game!" << endl;
			break;
		}

		while (true) {
			cout << endl << "Computer's turn..." << endl;			
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

