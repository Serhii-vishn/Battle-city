#include "Tank.h"

Level Tank::lvl;


void Tank::SetDirection(direction dirPl)
{
	dirTank = dirPl;
}

void Tank::SetPosition(int x, int y)
{
	this->X = x;
	this->Y = y;
}

void Tank::Init(classTank tank)
{
	X = 0;
	Y = 0;
	//vX = 0; vY = 0;
	speed = 1;
	//SetlvlPlayer(0);
	//SetStartPositionPlayer(120, 315);

	switch (tank)
	{
	case playerTank:
		spTankUp = createSprite("..\\res\\tank_up.png");
		spTankDown = createSprite("..\\res\\tank_down.png");
		spTankLeft = createSprite("..\\res\\tank_left.png");
		spTankRight = createSprite("..\\res\\tank_right.png");
		break;
	case playerFastTank:
		break;
	case playerPowerTank:
		break;
	case playerArmorTank:
		break;
	case enemyTank:
		break;
	case enemyFastTank:
		break;
	case enemyPowerTank:
		break;
	case enemyArmorTank:
		break;
	default:
		break;
	}
}

void Tank::Draw()
{
	switch (dirTank)
	{
	case up:
		drawSprite(spTankUp, X, Y);
		break;
	case left:
		drawSprite(spTankLeft, X, Y);
		break;
	case right:
		drawSprite(spTankRight, X, Y);
		break;
	case down:
		drawSprite(spTankDown, X, Y);
		break;
	default:
		break;
	}
}

void Tank::Drive()
{
	switch (dirTank)
	{
	case up:
		vY = -speed;
		break;
	case left:
		vX = -speed;
		break;
	case right:
		vX = speed;
		break;
	case down:
		vY = speed;
		break;
	}
}

void Tank::Stop(direction stD)
{
	vX = 0;
	vY = 0;
}

void Tank::Update()
{
	//X = 0; Y = 0;
	X += vX;
	Y += vY;
	if (X < 0)X = 0;
	if (X > 780)X = 780;
	if (Y < 0)Y = 0;
	if (Y > 700)Y = 700;
		

	//Game::lvl.GetBrick(x/14,y/14);


    if (vX < 0 && X > 0)
	{
		if (Tank::lvl.GetBrick(X / 30, X / 30) == redBrick)
		{
			Stop(dirTank);
		}
	}
}

void Tank::SetSpriteTank(classTank tank)

{	
	//delete spPlayerUp, spPlayerDown, spPlayerLeft, spPlayerRight;
	/*spTankUp = createSprite(sptankUp);
	spTankLeft = createSprite(sptankLeft);
	spTankRight = createSprite(sptankRight);
	spTankDown = createSprite(sptankDown);*/
	switch (tank)
	{
	case playerTank:
		spTankUp = createSprite("..\\res\\tank_up.png");
		spTankDown = createSprite("..\\res\\tank_down.png");
		spTankLeft = createSprite("..\\res\\tank_left.png");
		spTankRight = createSprite("..\\res\\tank_right.png");
		break;
	case playerFastTank:
		break;
	case playerPowerTank:
		break;
	case playerArmorTank:
		break;
	case enemyTank:
		break;
	case enemyFastTank:
		break;
	case enemyPowerTank:
		break;
	case enemyArmorTank:
		break;
	default:
		break;
	}
}

bool Tank::AliveOfDeth(bool alive)
{
	return alive;
}