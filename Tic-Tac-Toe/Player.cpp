#include "Player.h"
#include "Board.h"
#include <iostream>

using namespace std;

const char Player::PIECES[NUM_PIECES] = { 'X', 'O' };   // What the pieces are, we can change these to anything to make a silly game

int Player::current = 0;								// Current player, initialized at 0.
			
Player::Player()										// Player Piece
{
	m_Piece = PIECES[current];
	current = (current + 1) % NUM_PIECES;
}

Player::~Player()
{
}

char Player::GetPiece() const							// get the Piece associated with the player
{
	return m_Piece;
}

// Asks the player where they want to go, between 0-8

// Initialize Move to 0; or NULL;
// Prints out "Player X/O, Where would you like to move (0-8): then askes the player for their input for desired position
// Do this until we get a legal move
// Take in move, place Current players Piece on the board at indicated location
void Player::MakeMove(Board& Board) const
{
	int move;

	do
	{
		cout << "Player " << GetPiece();
		cout << ", where would you like to move? (0-8): ";
		cin >> move;
	} while (!Board.IsLegalMove(move));

	Board.ReceiveMove(GetPiece(), move);
}


char Player::GetOpponentPiece() const
{
	char piece;
	if (m_Piece == PIECES[FIRST])
	{ 
		piece = PIECES[FIRST];
	}  //Returns the Char thats not equal to the m_Piece, so if m_Piece is X make it O
	else 
	{ 
		piece = PIECES[SECOND];
	}					
	return piece;
}



