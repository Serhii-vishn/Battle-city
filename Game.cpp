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
		player.Update();
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
			//player.Stop(right);
			player.Stop();
			break;
		case FRKey::LEFT:
			player.Stop();
			break;
		case FRKey::DOWN:
			player.Stop();
			break;
		case FRKey::UP:
			player.Stop();
			break;
		default:
			break;
		}
		
	}

}