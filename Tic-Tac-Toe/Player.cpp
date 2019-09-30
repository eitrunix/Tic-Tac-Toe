#include "Player.h"
#include "Board.h"
#include <iostream>

using namespace std;

const char Player::PIECES[NUM_PIECES] = { 'X', 'O' };   // What the pieces are, we can change these to anything to make a silly game
int Player::current = 0;								// Current player, initialized at 0.
			
Player::Player()										// Player Pieces and current number of pieces
{
	m_Piece = PIECES[current];
	current = (current + 1) % NUM_PIECES;
}

char Player::GetPiece() const							// get the Piece associated with the player
{
	return m_Piece;
}

void Player::MakeMove(Board& aBoard) const				// Asks the player where they want to go, between 0-8
{
	int move;											// Initialize Move to 0; or NULL;
	do
	{
		cout << "Player " << GetPiece();					// Prints out "Player X/O, Where would you like to move (0-8): then askes the player for their input for desired position
		cout << ", where would you like to move? (0-8): ";
		cin >> move;
	} while (!aBoard.IsLegalMove(move));				// Do this until we get a legal move

	aBoard.ReceiveMove(GetPiece(), move);				// Take in move, place Current players Piece on the board at indicated location
}