#include <iostream>

using namespace std;

void print_board(char board[11][11]) {

	int i, j, index = 0;
	char alph[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

	cout << "\n\n\n";

	cout << "  1 2 3 4 5 6 7 8 9 10" << endl;

	for (i = 1; i <= 10; i++) {

		cout << alph[index] << " ";

		for (j = 1; j <= 10; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;

		index++;
	}

	cout << "\n\n\n";
}

void print_board_hide_boat(char board[11][11]) {

	int i, j, index = 0;
	char alph[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

	cout << "\n\n\n";

	cout << "  1 2 3 4 5 6 7 8 9 10" << endl;

	for (i = 1; i <= 10; i++) {

		cout << alph[index] << " ";

		for (j = 1; j <= 10; j++) {
			if (board[i][j] == 'X') cout << " ";
			else cout << board[i][j] << " ";
		}
		cout << endl;

		index++;
	}

	cout << "\n\n\n";

}

void initialize_board(char board[11][11]) {

	int i, j;

	for (i = 1; i <= 10; i++) {
		for (j = 1; j <= 10; j++) {

			board[i][j] = ' ';
		}
	}
}

int get_row_int(char row) {

	int i, save_i = 100;
	char alph[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

	for (i = 0; i < 10; i++) {

		if (row == alph[i]) save_i = i + 1;

	}

	return save_i;
}

void place_boat(char board[11][11], int boat_size) {

	int i;
	int row, col;
	int count_check;
	bool free_spot = false; // true means free spot
	bool repeat;
	char row_char;
	char orientation;

	cout << "Place " << boat_size << "-long boat" << endl;

	// input orientation

	while (!free_spot) { // check if place is free : execute as long as not free

		cout << "is the boat vertical or horizontal ? (h/v) ";
		cin >> orientation;

		while (orientation != 'h' && orientation != 'v') {
			cout << "Sorry, reply with \"h\" or \"v\" : ";
			cin >> orientation;
		}

		if (orientation == 'h') {

			// Horizontal

			// input row

			cout << "input row : ";
			cin >> row_char;

			row = get_row_int(row_char);

			while (row < 1 || row > 10) {
				cout << "Out of bound." << endl << "input row : ";
				cin >> row_char;
				row = get_row_int(row_char);
			}

			// input column

			cout << "input column : ";
			cin >> col;

			while (col < 1 || col >(11 - boat_size)) {
				cout << "Out of bound." << endl << "input column : ";
				cin >> col;
			}

			// Check if the spot is free

			count_check = col;

			repeat = true;

			for (i = col; i < col + boat_size; i++) {
				if (board[row][i] == 'X' && repeat) {
					cout << "That spot is taken ! \n\nReplace boat : " << endl;
					repeat = false;
				}
				else count_check++;
			}

			if (count_check == i) free_spot = true;

			// Put boat to board

			if (free_spot) {
				for (i = col; i < col + boat_size; i++) {
					board[row][i] = 'X';
				}
			}
		}

		else if (orientation == 'v') {

			// Vertical

			// input row

			cout << "input row : ";
			cin >> row_char;

			row = get_row_int(row_char);

			while (row < 1 || row >(11 - boat_size)) {

				cout << "Out of bound." << endl << "input row : ";
				cin >> row_char;
				row = get_row_int(row_char);
			}

			// input column

			cout << "input column : ";
			cin >> col;

			while (col < 1 || col > 10) {
				cout << "Out of bound." << endl << "input column : ";
				cin >> col;
			}

			// Check if spot is free
			
			count_check = row;

			repeat = true;

			for (i = row; i < row + boat_size; i++) {
				if (board[i][col] == 'X' && repeat) {
					cout << "That spot is taken ! \n\nReplace boat : " << endl;
					repeat = false;
				}
				else count_check++;
			}

			if (count_check == i) free_spot = true;

			// Put boat to board

			if (free_spot) {
				for (i = row; i < row + boat_size; i++) {
					board[i][col] = 'X';
				}
			}

		}

	}
}

void cpu_place_boat(char board[11][11], int boat_size) {

	int i;
	int row, col;
	int count_check;
	int iorientation;
	bool free_spot = false; // true means free spot
	bool repeat;
	char row_char;
	char orientation;

	srand(time(NULL));


	// orientation

	 // check if place is free : execute as long as not free

	while (!free_spot) {

		iorientation = rand() % 2;

		if (iorientation == 1) orientation = 'h';

		if (iorientation == 0) orientation = 'v';

		if (orientation == 'h') {

			// Horizontal

			// row from rand()

			row = rand() % 10 + 1;

			// column from rand()

			col = rand() % (10 - boat_size) + 1;


			// Check if the spot is free

			count_check = col;

			repeat = true;

			for (i = col; i < col + boat_size; i++) {
				if (board[row][i] == 'X' && repeat) {
					repeat = false;
				}
				else count_check++;
			}

			if (count_check == i) free_spot = true;

			// Put boat to board

			if (free_spot) {
				for (i = col; i < col + boat_size; i++) {
					board[row][i] = 'X';
				}
			}
		}

		else if (orientation == 'v') {

			// Vertical

			// row from rand()

			row = rand() % (11 - boat_size) + 1;

			// column from rand()

			col = rand() % 11 + 1;

			// Check if spot is free

			count_check = row;

			repeat = true;

			for (i = row; i < row + boat_size; i++) {
				if (board[i][col] == 'X' && repeat) {
					repeat = false;
				}
				else count_check++;
			}

			if (count_check == i) free_spot = true;

			// Put boat to board

			if (free_spot) {
				for (i = row; i < row + boat_size; i++) {
					board[i][col] = 'X';
				}
			}

		}

		else cout << "NOT h OR v" << endl;

	}
}

void player_turn(char board[11][11]) {

	int row, col;
	char row_char;

	cout << "Where do you want to hit ? " << endl << "row : ";
	cin >> row_char;

	// input row

	row = get_row_int(row_char);

	while (row < 1 || row > 10) {
		cout << "Out of bound." << endl << "row : ";
		cin >> row_char;
		row = get_row_int(row_char);
	}

	// input column

	cout << "column : ";
	cin >> col;

	while (col < 1 || col > 10) {
		cout << "Out of bound." << endl << "column : ";
		cin >> col;
	}

	// Check if the spot has a boat ( --> *)

	if (board[row][col] == 'X') {
		board[row][col] = '*';
		cout << "Hit ! " << endl;
	}

	// Check if the spot has nothing ( --> O)

	if (board[row][col] == ' ') {
		board[row][col] = 'O';
		cout << "Missed ! " << endl;
	}


}

void cpu_turn(char board[11][11]) {

	int row, col;

	cout << "Opponent's turn. " << endl;

	// row from rand()

	row = rand() % 10 + 1;

	// column from rand()

	col = rand() % 10 + 1;


	// Check if the spot has a boat

		// Check if the spot has a boat ( --> *)

	if (board[row][col] == 'X') {
		board[row][col] = '*';
		cout << "Hit ! " << endl;
	}

	// Check if the spot has nothing ( --> O)

	else if (board[row][col] == ' ') {
		board[row][col] = 'O';
		cout << "Missed ! " << endl;
	}

	else cout << "oops, cpu's turn did not go as expected. " << endl;

}

bool is_win(char board[11][11]) {

	int i, j;
	int count_boat = 0;

	for (i = 1; i <= 10; i++) {
		for (j = 1; j <= 10; j++) {
		
			if (board[i][j] == 'X') count_boat++;
		
		}
	}

	if (count_boat == 0) return true;

	else return false;

}

int main() {
	char board_player[11][11];
	char board_attack[11][11];

	// initialize board

	initialize_board(board_player);
	initialize_board(board_attack);

	int boat;

	// place cpu's boats

	for (boat = 5; boat >= 2; boat--) {
		cpu_place_boat(board_attack, boat);

		if (boat == 3) {
			cpu_place_boat(board_attack, boat);
		}
	}

	// place player's boats

	print_board(board_player);

	for (boat = 5; boat >= 2; boat--) {
		place_boat(board_player, boat);
		print_board(board_player);

		if (boat == 3) {
			place_boat(board_player, boat);
			print_board(board_player);
		}
	}

	

	// For testing purposes : automatically place player's boats 
	/*

	for (boat = 5; boat >= 2; boat--) {
		cpu_place_boat(board_player, boat);

		if (boat == 3) {
			cpu_place_boat(board_player, boat);
		}
	}

	print_board(board_player);

	*/

	cout << "You have placed your boats !\nGame starts !" << endl;

	print_board_hide_boat(board_attack);

	// Game loop

	bool victory_player = false;

	while (true) {

		player_turn(board_attack);
		print_board_hide_boat(board_attack);

		if (is_win(board_attack)) {
			victory_player = true;
			break;
		}

		cpu_turn(board_player);
		print_board(board_player);

		if (is_win(board_player)) break;

	}

	if (victory_player) cout << "Victory !" << endl;

	else cout << "You lost..." << endl;


	cout << "Game Over." << endl;

	return 0;
}
