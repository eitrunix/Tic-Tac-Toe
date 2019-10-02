#pragma once
#ifndef PLAYERHUMAN_H
#define PLAYERHUMAN_H

#include "Player.h"

class Board;

class PlayerHuman : public Player
{

public:
	virtual void MakeMove(Board& Board) const;
};
#endif