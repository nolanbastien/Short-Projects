#include <iostream>
#include <stdio.h>

using namespace std;

void print_board(char board[]) {

	int i, j, index = 1;

	for (i = 1; i <= 3; i++) {

		cout << "|";

		for (j = 1; j <= 3 ; j++) {
		
			cout << board[index] << "|";

			index++;
		
		}
	
		cout << endl;
	
	}

}

int player_turn(char board [], char player) {

	int place;

	cout << "Player " << player << "'s turn. Enter (1-9) : ";

	cin >> place;

	if (board[place] == ' ') {
		board[place] = player;
		return 0;
	}

	else {
		cout << "Sorry place taken !" << endl;
		return 1;
	}
	

}

int is_victory(char board[], char player) {

	// rows

	if (board[1] == player && board[2] == player & board[3] == player) { cout << "\nPlayer " << player << " wins ! ";  return 1; }
	if (board[4] == player && board[5] == player & board[6] == player) { cout << "\nPlayer " << player << " wins ! ";  return 1; }
	if (board[7] == player && board[8] == player & board[9] == player) { cout << "\nPlayer " << player << " wins ! ";  return 1; }

	// columns

	if (board[1] == player && board[4] == player & board[7] == player) { cout << "\nPlayer " << player << " wins ! ";  return 1; }
	if (board[2] == player && board[5] == player & board[8] == player) { cout << "\nPlayer " << player << " wins ! ";  return 1; }
	if (board[3] == player && board[6] == player & board[9] == player) { cout << "\nPlayer " << player << " wins ! ";  return 1; }

	// diagonals

	if (board[1] == player && board[5] == player & board[9] == player) { cout << "\nPlayer " << player << " wins ! ";  return 1; }
	if (board[3] == player && board[5] == player & board[7] == player) { cout << "\nPlayer " << player << " wins ! ";  return 1; }

	return 0;

}

int main() { 

	int i;
	int play = 1;
	char board[10];

	for (i = 1; i <= 9; i++) {
	
		board[i] = ' ';
	
	}

	while (1) {

		print_board(board);

		play = 1;
		while (play) {
			play = player_turn(board, 'X');
		}

		print_board(board);

		if(is_victory(board, 'X')) break;

		play = 1;
		while (play) {
			play = player_turn(board, 'O');
		}

		if (is_victory(board, 'O')) break;

	}

	cout << "\n\nGame Over.\n\n";

	getchar();
	getchar();

	return 0;

}
