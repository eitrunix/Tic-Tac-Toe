#pragma once
#ifndef BOARD_H
#define BOARD_H


class Board
{
public:
	Board();
	bool IsFull() const;					//For checking if the board is full or not
	bool IsLegalMove(int move) const;		//Check if the players move is valid
	bool IsWinner(char piece) const;		//Check for a winner 
	void Display() const;					// Print the board
	void Reset();							// Reset the board
	void RecieveMove(char piece, int move);	// Takes in player input to place a piece

	static const int NUM_SQUARES = 9;		// Number of spaces in the game
	static const char EMPTY = ' ';			// If the space is empty, print out an empy space

private:
	static const int NUM_COMBOS = 8;		// How many Winning combos there are
	static const int NUM_IN_COMBO = 3;		// How many numbers in a combo to win
	static const int WINNING_COMBOS[NUM_COMBOS][NUM_IN_COMBO];		// The Winning combos. all of them.
	char m_Squares[NUM_SQUARES];			// Spaces i nthe game, used to change from a space to X/O
};

#endif




