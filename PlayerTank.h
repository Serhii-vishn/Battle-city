#pragma once
#include "Tank.h"
#include "Types.h"

class PlayerTank:public Tank
{
private:
	int lvlplayer;
	int lives;
	bool alive;
	double timeAchievement;
	bool invulnerability;

public:
	void initPlayer();

	void SetlvlPlayer(int lvl);


};

