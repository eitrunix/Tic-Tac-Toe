#include "Player.h"
#include "Board.h"
#include <iostream>

using namespace std;

const char Player::PIECES[NUM_PIECES] = { 'X', 'O' };
int Player::current = 0;

Player::Player()
{
	m_Piece = PIECES[current];
	current = (current + 1) % NUM_PIECES;
}

char Player::GetPiece() const
{
	return m_Piece;
}

void Player::MakeMove(Board& aBoard) const
{
	int move;
	do
	{
		cout << "Player " << GetPiece();
		cout << ", where would you like to move? (0-8): ";
		cin >> move;
	} while (!aBoard.IsLegalMove(move));

	aBoard.ReceiveMove(GetPiece(), move);
}