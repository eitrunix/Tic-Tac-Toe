#include "Game.h"
#include <iostream>

using namespace std;

int main()
{
	Game ticTacToe;							// Make child of the Game class called ticTacToe
	ticTacToe.DisplayInstructions();		// Display Instructions for this new class

	char again;				// Ask to play again
	do
	{
		ticTacToe.SetPlayers();
		ticTacToe.Play();
		std::cout << std::endl << "Play again? (y/n): ";
		std::cin >> again;
	} while (again != 'n');  //If y then play again, if n then quits.

	std::cout << "Thanks for playing!";
	std::cin.get();       // This pauses the game, and waits for any input/keypress. then will exit the gmae.
	return 0;
}
