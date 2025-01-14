#pragma once
#ifndef GAME_H
#define GAME_H

#include "Board.h"
class Player;

class Game
{
public:
	Game();									// The "Game" You just lost it.
	~Game();							// Frees memory occupied by Player objects
	bool IsPlaying() const;					// Function for "Running" the game
	bool IsTie() const;						// Check for a tie.
	void ClearPlayers();					// Frees memory occupied by Player objects
	void SetPlayers();
	void DisplayInstructions() const;		// Display the Instructions.
	void NextPlayer();						// Swap current player
	void AnnounceWinner() const;			// Announce a Winner
	void Play();							// The function to run the functions that makes the game look like a game.

private:
	static const int NUM_PLAYERS = 2;		// Number of players
	static const int FIRST = 0;				// First Player var
	static const int SECOND = 1;			// Second player var

	Board m_Board;							// Creat a board from the Board class
	Player* m_pPlayers[NUM_PLAYERS];			// create players from the Player Class equal to NUM_PLAYERS
	int m_Current;							// Current player var
};

#endif