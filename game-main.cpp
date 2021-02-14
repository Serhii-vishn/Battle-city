#include "Framework.h"
#include "Tank.h"
#include "Types.h"
#include "PlayerTank.h"
#include "Game.h"

int WinWidth = 1000;
int WinHeight = 750;

/* Test Framework realization */
class MyFramework : public Framework {
	Game tankpl;

public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = WinWidth;
		height = WinHeight;
		fullscreen = false;
	}

	virtual bool Init() {
		tankpl.Init();
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
   // drawTestBackground();
		tankpl.Draw();
		//tankpl.Update();
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		//std::cout << x << "-" << y << "\n";
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

	virtual void onKeyPressed(FRKey k) {
		tankpl.PlayerMove(k, true);
		/*switch (k)
		{
		case FRKey::RIGHT:
			tankpl.SetDirection(right);
			tankpl.Drive();
			break;
		case FRKey::LEFT:
			tankpl.SetDirection(left);
			tankpl.Drive();
			break;
		case FRKey::DOWN:
			tankpl.SetDirection(down);
			tankpl.Drive();
			break;
		case FRKey::UP:
			tankpl.SetDirection(up);
			tankpl.Drive();
			break;
		default:
			break;
		}*/

	}

	virtual void onKeyReleased(FRKey k) {
		tankpl.PlayerMove(k, false);
		/*switch (k)
		{
		case FRKey::RIGHT:
			tankpl.Stop(right);
			break;
		case FRKey::LEFT:
			tankpl.Stop(left);
			break;
		case FRKey::DOWN:
			tankpl.Stop(down);
			break;
		case FRKey::UP:
			tankpl.Stop(up);
			break;
		default:
			break;
		}*/



	}
	
	virtual const char* GetTitle() override
	{
		return "Tanks";
	}
};

int main(int argc, char *argv[])
{
	return run(new MyFramework);
}
