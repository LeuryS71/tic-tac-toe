#include <iostream>
#include <string>
#include <tictactoe.h>
using namespace std;


tictactoe::tictactoe(){
	tMoves = 0;
	fboard();
	}

void tictactoe::fboard() {
	for (int row = 0; row < B_SIZE; row++) {
		for (int col = 0; col < B_SIZE;col++) {
			board[row][col] = ' ';
		}
	}
}
void tictactoe::displayBoard()const {
	cout << " --------------\n";
	for (int row = 0; row < B_SIZE; row++) {
		cout << " | ";
		for (int col = 0; col < B_SIZE; col++) {
			cout <<  board[row][col] << "  |";
		}

		cout << "\n --------------\n";
	}
}
void tictactoe::getMove(char player){
	string input;
	char char_entered;
	int num_entered, row, col, i;

	while (true) {
		cout << player << " Choose your placement. Select a number from 1-9: " << endl;
		getline(cin, input);

		if (input != "") {

			char_entered = input.c_str()[0];
			if (char_entered >= '1' && char_entered <= '9') {

				num_entered = char_entered - '0';
				i = num_entered - 1;

				row = i / 3;
				col = i % 3;
				char b_pos = board[row][col];
				if (b_pos != 'X' && b_pos != 'O') {
					board[row][col] = player;
					tMoves++;
					break;
				}
				else
					cout << "Wrong move. Position is already taken. Try again" << endl;
			}
			else
				cout << "You can only choose between 1-9 to move place your position."
				<< "Try again. \n";
		}
		else
			cout << "You must enter something!!" << endl;
	}
	cout << "Total moves: " << this->tMoves << endl;
}

char tictactoe::tPlayer(char player) {

	player = player == 'X' ? 'O' : 'X';
	return (player);
}

bool tictactoe::cWins(char player)const{


	if (tMoves >= mnMoves) {
		if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
			return true;
		}
		if (board[1][0] == player && board[1][1] == player && board[1][2] == player)
		{
			return true;
		}
		if (board[2][0] == player && board[2][1] == player && board[2][2] == player)
		{
			return true;
		}

		if (board[0][0] == player && board[1][0] == player && board[2][0] == player)
		{
			return true;
		}
		if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
		{
			return true;
		}
		if (board[0][2] == player && board[1][2] == player && board[2][2] == player)
		{
			return true;
		}

		if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		{
			return true;
		}
		if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
		{
			return true;
		}

	}
	return false;

}

bool tictactoe::cDraw()const{
	return tMoves == mxMoves;
}

void tictactoe::playGame(){
	char player = 'X';
	bool gameOver = false;

	do {
		displayBoard();
		getMove(player);
		if (cWins(player)) {
			cout << "\n YOU ARE THE WINNER!!" << endl
			 << player << "WINS!!";
			gameOver = true;
		}
		else if (cDraw()) {
			cout << "IT'S A DRAW!" << endl;
			gameOver = true;
		}
		player = tPlayer(player);
	} while (!gameOver);

	displayBoard();
}




int main() {
	tictactoe game;
	game.playGame();
	return 0;
}
