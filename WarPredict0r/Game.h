#pragma once

#include "Player.h"

class Game
{
public:
	void Init();
	void Run();

private:
	void SimulateRound();
	void CheckWin();

private:
	Player p1;
	Player p2;
};

