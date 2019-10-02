#include "playercomputer.h"
#include <iostream>
#include "Board.h"

using namespace std;

PlayerComputer::MakeMove(Board& Board) const
{
	int move = 0;
	bool found = false;
	   // If the computer can Win on the next move, thats the move to make
	while (!found && move < Board.NUM_SQUARES)
	{
		if (Board.IsLegalMove(move))
		{
			//try move
			Board.RecieveMove(GetPiece(), move);
			//Test for Winner
			found = Board.IsWinner(GetPiece());
			//undo move
			Board.RecieveMove(Board.EMPTY, move);
		}

		if (!found)
		{
			++move;
		}
	}

	if (!found)
	{
		move = 0;

		while (!found && move < Board.NUM_SQUARES)
		{
			if (Board.IsLegalMove(move)) 
			{
				Board.RecieveMove(GetOpponentPiece(), move);
				found = Board.IsWinner(GetOpponentPiece());
				Board.RecieveMove(Board.EMPTY, move);
			}
			if (!found)
			{
				++move;
			}
		}
	}

	if (!found)
	{
		move = 0;
		int i = 0;

		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		while(!found && i < Board.NUM_SQUARES)
		{
			move = BEST_MOVES[i];
			if (Board.IsLegalMove(move))
			{
				found = true;
			}
			i++;
		}
	}

	std::cout << "I, Player " << GetPiece();
	std::cout << ", shall take the square number ";
	std::cout << move << "." << endl;

	Board.RecieveMove(GetPiece(), move)
}