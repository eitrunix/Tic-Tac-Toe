#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"
#ifndef GAME_H
#define GAME_H
using namespace std;

class Game
{
public:
	Game();
	bool IsPlaying() const;
	bool IsTie() const;
	void DisplayInstructions() const;
	void NextPlayer();
	void AnnounceWinner() const;
	void Play();

private:
	static const int NUM_PLAYERS = 2;
	static const int FIRST = 0;
	static const int SECOND = 1;

	Board m_Board;
	Player m_Players[NUM_PLAYERS];
	int m_Current;
};

#endif