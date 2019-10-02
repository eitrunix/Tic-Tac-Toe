#include "playerHuman.h"
#inclide "Board.h"
#inclide <iostream>
using namespace std;

PlayerHuman::MakeMove(Board& Board) const
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

