#ifndef PLAYERCOMPUTER_H
#define PLAYERCOMPUTER_H

#include "Player.h"

class Board;

class PlayerComputer : public Player
{
public:
	
	virtual void MakeMove(Board& Board) const override;  //Calculates and makes a move

};

#endif