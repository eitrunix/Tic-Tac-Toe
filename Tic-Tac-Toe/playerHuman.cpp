#include "playerHuman.h"
#include "Board.h"
#include <iostream>
using namespace std;

void PlayerHuman::MakeMove(Board& Board) const
{
	int move;

	do
	{
		cout << "Player " << GetPiece();
		cout << ", Where would you like to move? (0-8): ";
		cin >> move;

	} while (!Board.IsLegalMove(move));
	Board.RecieveMove(GetPiece(), move);
}

