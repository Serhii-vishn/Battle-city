#include "Game.h"

PlayerTank Game::player;
Level Game::lvl;

void Game::Init()
{
	lvl.Init();
	lvl.Loadlvl();
	player.initPlayer();

}

void Game::Draw()
{
	lvl.Draw();
	player.Update();
	player.Draw();
}


void Game::PlayerMove(FRKey k, bool press)
{
	if (press == true)
	{
		switch (k)
		{
		case FRKey::RIGHT:
			player.SetDirection(right);
			player.Drive();
			break;
		case FRKey::LEFT:
			player.SetDirection(left);
			player.Drive();
			break;
		case FRKey::DOWN:
			player.SetDirection(down);
			player.Drive();
			break;
		case FRKey::UP:
			player.SetDirection(up);
			player.Drive();
			break;
		default:
			break;
		}
	}
	else if (press == false)
	{
		switch (k)
		{
		case FRKey::RIGHT:
			player.Stop(right);
			break;
		case FRKey::LEFT:
			player.Stop(left);
			break;
		case FRKey::DOWN:
			player.Stop(down);
			break;
		case FRKey::UP:
			player.Stop(up);
			break;
		default:
			break;
		}
	}



}

