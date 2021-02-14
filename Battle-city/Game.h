#pragma once

#include "PlayerTank.h"
#include "Level.h"
#include "Types.h"


class Game
{
private:
	static PlayerTank player;
	static Level lvl;

public:
	void Init();
	void Draw();

	void PlayerMove(FRKey k, bool press);
};

