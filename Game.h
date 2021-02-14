#pragma once

#include "PlayerTank.h"
#include "Level.h"
#include "Types.h"


class Game
{
private:
	bool flag;
public:
	static PlayerTank player;
	static Level lvl;
	void Init();
	void Draw();

	void PlayerMove(FRKey k, bool press);


};