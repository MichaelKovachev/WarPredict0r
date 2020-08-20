#pragma once

#include "Player.h"

class Game
{
public:
	void SimulateRound();
	void CheckWin();

private:
	Player p1;
	Player p2;
};

