#include "Board.h"
#include <iostream>

using namespace std;
// Sets up the winning combos, YOu need thses to win/lose
const int Board::WINNING_COMBOS[NUM_COMBOS][NUM_IN_COMBO] =
{ {0,1,2},
  {3,4,5},
  {6,7,8},
  {0,3,6},
  {1,4,7},
  {2,5,8},
  {0,4,8},
  {2,4,6}, };

// //Resets the board after the game is done and the player wants to play again, defnes the board scope with Reset();
Board::Board()
{
	//  Resets the board
	Reset();
}
// Checks if the board is full, for checking hte win condition
bool Board::IsFull() const
{
	bool full = true;
	int i = 0;

	while (full && i < NUM_SQUARES)
	{
		if (m_Squares[i] == EMPTY) // if the space is empty, the board isnt full and we can keep going.
		{
			full = false;
		}
		++i;
	}
	return full;
}
// Checks for a legal move. if the space is empty, its a legal move
bool Board::IsLegalMove(int move) const
{
	return (move >= 0 && move < NUM_SQUARES && m_Squares[move] == EMPTY);
}

// Checks the Winning combos to see if anyone has won yet
bool Board::IsWinner(char piece) const
{
	bool winner = false;
	int i = 0;
	while (!winner && i < NUM_COMBOS)
	{
		int piecesInCombo = 0;
		for (int j = 0; j < NUM_IN_COMBO; ++j)
		{
			if (m_Squares[WINNING_COMBOS[i][j]] == piece)
			{
				++piecesInCombo;
			}
		}

		if (piecesInCombo == NUM_IN_COMBO)
		{
			winner = true;
		}
		++i;
	}
	return winner;
}
// Basic display for the board, very very simple.
void Board::Display() const
{
	cout << endl << "\t" << m_Squares[0] << " | " << m_Squares[1];cout << " | " << m_Squares[2];
								cout << endl << "\t" << "---------";
	cout << endl << "\t" << m_Squares[3] << " | " << m_Squares[4];cout << " | " << m_Squares[5];
								cout << endl << "\t" << "---------";
	cout << endl << "\t" << m_Squares[6] << " | " << m_Squares[7];cout << " | " << m_Squares[8];
	cout << endl << endl;
}
//defines the reset function, just sets the spaces to empty
void Board::Reset()
{
	for (int i = 0; i < NUM_SQUARES; i++)
	{
		m_Squares[i] = EMPTY;
	}
}
// used for placing the pieces.
void Board::ReceiveMove(char piece, int move)
{
	m_Squares[move] = piece;
}