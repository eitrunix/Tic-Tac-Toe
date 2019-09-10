#include "Game.h"
#include <iostream>

using namespace std;

int main()
{
	Game ticTacToe;
	ticTacToe.DisplayInstructions();

	char again;
	do
	{
		ticTacToe.Play();
		cout << endl << "Play again? (y/n): ";
		cin >> again;
	} while (again != 'n');
	return 0;
}
