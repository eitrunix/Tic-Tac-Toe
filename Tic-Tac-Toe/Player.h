#pragma once
#ifndef PLAYER_H
#define PLAYER_H
class Board;				// the Board Class...again... Game wont run without this, I feel like I did something wrong??

class Player				// Building the Player Class.
{
public:
	Player();				// To check if firset or second player
	virtual ~Player();		//
	char GetPiece() const;	// check If the current player is X or O
	char GetOpponentPiece() const;
	virtual void MakeMove(Board& Board) const = 0; // Making a move

private:
	static const int NUM_PIECES = 2;		// Number of different pieces, 2 = X/O
	static const int FIRST = 0;
	static const int SECOND = 0;
	static const char PIECES[NUM_PIECES];	// Array for the 2 pieces.. this seems weird but Ill go with it.
	static int current;						// for checking hte current piece

	char m_Piece;							
};
#endif

