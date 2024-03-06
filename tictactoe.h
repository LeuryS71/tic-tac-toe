#ifndef TICTACTOE_H
#define TICTACTOE_H

class tictactoe
{
    public:
	tictactoe();
	void displayBoard()const;
	void getMove(char player);
	void playGame();
private:
	static const int B_SIZE = 3;
	static const int mxMoves = 9;
	static const int mnMoves = 5;
	char board[B_SIZE][B_SIZE];
	int tMoves;
	bool cWins(char player)const;
	bool cDraw()const;
	void fboard();
	char tPlayer(char player);
};

#endif
