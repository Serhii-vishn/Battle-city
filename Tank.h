#pragma once
#include "Framework.h"
#include "Types.h"
#include <iostream>
#include "Level.h"

class Tank
{
protected:
	Sprite *spTankUp, *spTankLeft, *spTankRight, *spTankDown; //sprites for rendering the tank texture

	int X, Y;//coordinates of tank
	//int startx, starty;
	int vX, vY;
	int speed;//speed of tank
	direction dirTank;

	int maxBullet;//number of shots
	int powerBullet;// power of shot
	int speedBullet;//projectile speed (1-slow, 2-noaml, 3-fast)

	bool flagGo;

public:
	//initialization and drawing of the tank
	void Init(classTank tank);
	//void SetlvlPlayer(int lvl);
	void Draw();

	//description of tank actions
	void Drive();
	void Stop();

	void StopTank(int x, int y);
	void SetDirection(direction dirPl);
	void Update();
	void SetSpriteTank(classTank tank);

	int GetVx();
	int GetVy();
	int GetX();
	int GetY();


	void SetInvulnerability(double time_inv);
	bool GetInvulnerability();

	bool AliveOfDeth(bool alive);
	//void SetStartPositionPlayer(int startx, int starty);
	void SetPosition(int x, int y);

	void RespawnPlayer();
};