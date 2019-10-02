#ifndef PLAYERCOMPUTER_H
#define PLAYERCOMPUTER_H

#include "Player.h"

class Board;

class PlayerComputer : public Player
{
public:
	//Calculates and makes a move
	virtual void MakeMove(Board& Board) const;

};

#endif