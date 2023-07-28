/*
Cameron Candau
CS11 Assignment 7
Purpose: Allows two people to play a game of tic tac toe.
A move is made by entering the desired row and column.
*/
#include <iostream>

using namespace std;

class TicTacToe{

public:
  TicTacToe();
  void play();
private:
	char sigil[3] = {'.','X','O'};
	int board[3][3];
	int winner(int board[3][3]);
	bool isGameOver(int board[3][3]);
	void drawBoard(int board[3][3]);
	bool isMoveLegal(int board[3][3], int row, int column);
};

// constructor that sets each location of the board equal to 0 and defines the 3 SIGILs that will be used on the playing board for a blank space ".", player 1 "X", and player 2 "O"
TicTacToe::TicTacToe(){
	for(int r=0; r<3; r++)
		for (int c=0; c<3; c++)
			board[r][c] = 0;
	sigil[0]='.';

	sigil[1]='X';

	sigil[2]='O';
}

// Calls other member functions and allows the user to play tic tac toe through typing the row and column 
void TicTacToe::play(){
  int player = 1;
  int row, column, result;
  bool legalMove;
  
  // starting board
  drawBoard(board);
  while(!isGameOver(board)){
    cout << "Player " << player << "(" << sigil[player] << "), your move?";
    cin >> row >> column;
    legalMove = isMoveLegal(board, row, column);
    while(!legalMove){
      cout << "Player " << player << "(" << sigil[player] << "), your move?";
      cin >> row >> column;
      legalMove = isMoveLegal(board, row, column);
    }
    board[row][column] = player;
    drawBoard(board);
    player = 3 - player;
  }
  // game over
  result = winner(board);
  if (result == 0){
    cout << "Tie Game" << endl;
  } else {
    cout << "Player " << result << "(" << sigil[result] << ") wins!" << endl;
  }
}

//checks all the possible rows, columns, and diagonals for a win condition (3 of one players' sigil in a row). Returns 1 for player 1 (X) win, 2, for player 2 (O) win, 
//and 0 for neither
int TicTacToe::winner(int board[3][3]){
	//col check
	for (int col = 0; col <= 2; col++){
		if ((board[0][col] == 1) && (board [1][col] == 1) && (board[2][col] == 1)){
			return 1;}
		else if ((board[0][col] == 2) && (board[1][col] == 2) && (board[2][col] == 2)){
			return 2;}
	}

	//row check
	for (int row = 0; row <= 2; row++){
		if ((board[row][0] == 1) && (board[row][1] == 1) && (board[row][2] == 1)){
			return 1;}
		else if ((board[row][0] == 2) && (board[row][1] == 2) && (board[row][2] == 2)){
			return 2;}
	}
	
	//diagonal (top left to bottom right) check
	if ((board[0][0] == 1) && (board[1][1] == 1) && (board[2][2] == 1)){
		return 1;}
	else if ((board[0][0] == 2) && (board[1][1] == 2) && (board[2][2] == 2)){
		return 2;}

	//diagonal (bottom left to top right) check
	if ((board[2][0] == 1) && (board[1][1] == 1) && (board[0][2] == 1)){
		return 1;}
	if ((board[2][0] == 2) && (board[1][1] == 2) && (board[0][2] == 2)){
		return 2;}
	// by now, all the checks have happened, so if neither 1 nor 2 have been returned, there is no win condition yet so return 0
	return 0;
}

//returns true if there is a winner or if all the spaces are taken on the board. Returns false if there are still spaces available on the board
bool TicTacToe::isGameOver(int board[3][3]){
  if (winner(board) == 1 || winner(board) == 2) return true;
  for(int r=0; r<=2; r++)
    for (int c=0; c<=2; c++)
      if (board[r][c] == 0)
	return false;
  return true;
}

//draws the playing board including the row and column label numbers
void TicTacToe::drawBoard(int board[3][3]){
	cout << "  0 1 2" << endl;
	for (int row = 0; row <= 2; row++){
		cout << row << " ";
		for (int col = 0; col <= 2; col++){
			if (board[row][col] == 1){
				cout << sigil[1];}
			else if (board[row][col] == 2){
				cout << sigil[2];}
			else {cout << sigil[0];}
			cout << " ";
		}
	cout << endl;
	}
}

//Returns false if the player's move is outside the bounds of the playing board (0-2) or if their input already has a player's sigil at that location.
//Returns true if everything above is false, meaning that the input is within the board bounds and the location of the input is empty
bool TicTacToe::isMoveLegal(int board[3][3], int row, int column){
	if (row > 2 || row < 0){
		return false;}
	else if (column > 2 || column < 0){
		return false;}
		
	if (board[row][column] != 0){
		return false;}	
	return true;
}


//creates an instance (object) of the TicTacToe class called game, and starts that game using the tictactoe member function "play"
int main(){
  TicTacToe game;
  game.play();
  return 0;
}
