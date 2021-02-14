#include "Level.h"

void Level::Init()
{
	delete spEmpty, spRedBrick, spWhiteBrick;
	spEmpty = createSprite("..\\res\\empty.png");
	spRedBrick = createSprite("..\\res\\red_brick.png");
	spWhiteBrick = createSprite("..\\res\\white_brick.png");
}

void Level::Draw()
{
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 28; x++)
		{
			switch (lvl[y][x])
			{
			case empty:
				drawSprite(spEmpty, x*30 , y * 30);
				break;
			case redBrick:
				drawSprite(spRedBrick, x * 30, y * 30);
				break;
			case whiteBrick:
				drawSprite(spWhiteBrick, x * 30, y * 30);
				break;
			case respawn:
				drawSprite(spEmpty, x * 30, y * 30);
				break;
			case base:
				//drawSprite(spBase, x, y);
				break;
			default:
				break;
			}
		}
	}
}


void Level::Loadlvl()
{
	std::ifstream file("..\\res\\Level_1.txt");
	if (!file)
	{
		std::cout << "Error! File with lvl doesn`t find\n\n";
		return;
	}
	else
	{
		std::string line;
		int y = -1;
		while (!file.eof())
		{
			std::getline(file, line);
			y++;
			for (int x = 0; x < line.size(); x++)
			{
				switch (line.at(x))
				{
				case '0':
					lvl[y][x] = empty;
					break;
				case '1':
					lvl[y][x] = redBrick;
					break;
				case '2':
					lvl[y][x] = whiteBrick;
					break;
				case '4':
					lvl[y][x] = grass;
					break;
				case '5':
					lvl[y][x] = base;
					break;
				case'R':
					lvl[y][x] = respawn;
					break;
				default:
					break;
				}
			}
		}
	}
	file.close();
}

level Level::GetBrick(int x, int y)
{
	//std::cout << lvl[y][x];
	return lvl[y][x];
}

