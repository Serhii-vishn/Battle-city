#include "PlayerTank.h"

void PlayerTank::initPlayer()
{
	Tank::Init(playerTank);

	invulnerability = false;
	SetlvlPlayer(0);

}

void PlayerTank::SetlvlPlayer(int lvl)
{
	lvlplayer = lvl;
	//delete spPlayerUp, spPlayerDown, spPlayerLeft, spPlayerRight;
	switch (lvlplayer)
	{
	case 0://default lvl
		/*spPlayerUp = createSprite("..\\res\\tank_up.png");
		spPlayerDown = createSprite("..\\res\\tank_down.png");
		spPlayerLeft = createSprite("..\\res\\tank_left.png");
		spPlayerRight = createSprite("..\\res\\tank_right.png");*/
		//Tank::SetSpriteTank(playerTank);
		maxBullet = 1;
		powerBullet = 1;
		speedBullet = 1;
		break;
	case 1://1st lvl
		maxBullet = 1;
		powerBullet = 1;
		speedBullet = 2;
		break;
	case 2://2nd lvl
		maxBullet = 2;
		powerBullet = 1;
		speedBullet = 2;
		break;
	case 3://3rd lvl

		maxBullet = 2;
		powerBullet = 2;
		speedBullet = 2;
		break;
	default:
		break;
	}
}