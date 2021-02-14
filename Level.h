#pragma once
#include "Types.h"
#include "Framework.h"
#include <string>
#include <fstream>
#include <iostream>
class Level
{
protected:
	const int lvlWidth = 28;
	const int lvlHeight = 25;
	level lvl[25][28];
	Sprite *spEmpty, *spWhiteBrick, *spRedBrick, *spBase;

public:

	void Init();

	void Draw();
	void Loadlvl();
	void SetBrick();

	level GetBrick(int x, int y);




};

