#include "Tank.h"
#include "Game.h"
void Tank::SetDirection(direction dirPl)
{
	dirTank = dirPl;
}

void Tank::SetPosition(int x, int y)
{
	this->X = x;
	this->Y = y;
}

int Tank::GetVx()
{
	return vX;
}
int Tank::GetVy()
{
	return vY;
}
int Tank::GetY()
{
	return Y;
}
int Tank::GetX()
{
	return X;
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

void Tank::Stop()
{
	vX = 0;
	vY = 0;
}

void Tank::StopTank(int x, int y)
{
	vX = 0;
	vY = 0;
	X = x;
	Y = y;
}

void Tank::Update()
{
	if (X < 0)X = 0;
	if (X > 799)X = 799;
	if (Y < 0)Y = 0;
	if (Y > 710)Y = 710;

	if (vX < 0 && X > 0)
	{
		if (Game::lvl.GetBrick((X - 1) / 30, Y / 30) == redBrick ||
			Game::lvl.GetBrick((X - 1) / 30, Y / 30) == whiteBrick ||
			Game::lvl.GetBrick((X - 1) / 30, Y / 30) == redBrickDamage ||
			Game::lvl.GetBrick((X - 1) / 30, Y / 30) == base ||
			Game::lvl.GetBrick((X - 1) / 30, Y / 30) == water ||
				Game::lvl.GetBrick((X - 1) / 30, (Y + 40) / 30) == redBrick||
				Game::lvl.GetBrick((X - 1) / 30, (Y + 40) / 30) == whiteBrick ||
				Game::lvl.GetBrick((X - 1) / 30, (Y + 40) / 30) == redBrickDamage ||
				Game::lvl.GetBrick((X - 1) / 30, (Y + 40) / 30) == base ||
				Game::lvl.GetBrick((X - 1) / 30, (Y + 40) / 30) == water)
		{
			Stop();
		}
	}
	else if (vX > 0 && X > 0)
	{
		 if (Game::lvl.GetBrick((X + 41) / 30, Y / 30) == redBrick ||
			Game::lvl.GetBrick((X + 41) / 30, Y / 30) == whiteBrick ||
			Game::lvl.GetBrick((X + 41) / 30, Y / 30) == redBrickDamage ||
			Game::lvl.GetBrick((X + 41) / 30, Y / 30) == base ||
			Game::lvl.GetBrick((X + 41) / 30, Y / 30) == water||
				Game::lvl.GetBrick((X + 41) / 30, (Y + 40) / 30) == redBrick ||
				Game::lvl.GetBrick((X + 41) / 30, (Y + 40) / 30) == whiteBrick ||
				Game::lvl.GetBrick((X + 41) / 30, (Y + 40) / 30) == redBrickDamage ||
				Game::lvl.GetBrick((X + 41) / 30, (Y + 40) / 30) == base ||
				Game::lvl.GetBrick((X + 41) / 30, (Y + 40) / 30) == water)
		 {
			 Stop();
		 }
	}

	if (vY < 0 && Y > 0)
	{

		if (Game::lvl.GetBrick(X / 30, (Y - 1) / 30) == redBrick ||
			Game::lvl.GetBrick(X / 30, (Y - 1) / 30) == whiteBrick ||
			Game::lvl.GetBrick(X / 30, (Y - 1) / 30) == redBrickDamage ||
			Game::lvl.GetBrick(X / 30, (Y - 1) / 30) == base ||
			Game::lvl.GetBrick(X / 30, (Y - 1) / 30) == water||
				Game::lvl.GetBrick((X + 40) / 30, (Y - 1) / 30) == redBrick ||
				Game::lvl.GetBrick((X + 40) / 30, (Y - 1) / 30) == whiteBrick ||
				Game::lvl.GetBrick((X + 40) / 30, (Y - 1) / 30) == redBrickDamage ||
				Game::lvl.GetBrick((X + 40) / 30, (Y - 1) / 30) == base ||
				Game::lvl.GetBrick((X + 40) / 30, (Y - 1) / 30) == water)
		{
			Stop();
		}

	}
	else if (vY > 0 && Y > 0)
	{
		if (Game::lvl.GetBrick(X / 30, (Y + 41) / 30) == redBrick ||
			Game::lvl.GetBrick(X / 30, (Y + 41) / 30) == whiteBrick ||
			Game::lvl.GetBrick(X / 30, (Y + 41) / 30) == redBrickDamage ||
			Game::lvl.GetBrick(X / 30, (Y + 41) / 30) == base ||
			Game::lvl.GetBrick(X / 30, (Y + 41) / 30) == water ||
				Game::lvl.GetBrick((X + 40) / 30, (Y + 41) / 30) == redBrick ||
				Game::lvl.GetBrick((X + 40) / 30, (Y + 1) / 30) == whiteBrick ||
				Game::lvl.GetBrick((X + 40) / 30, (Y + 1) / 30) == redBrickDamage ||
				Game::lvl.GetBrick((X + 40) / 30, (Y + 1) / 30) == base ||
				Game::lvl.GetBrick((X + 40) / 30, (Y + 1) / 30) == water)
		{
			Stop();
		}
	}


	X += vX;
	Y += vY;

}

void Tank::SetSpriteTank(classTank tank)
{	
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