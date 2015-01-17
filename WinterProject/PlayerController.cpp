#include "PlayerController.h"
#include "GameObject.h"

PlayerController::PlayerController(Player* playerRef)
{
	thePlayer = playerRef; //maybe not needed? look into casting
	componentName = "PlayerControllerComponent";
	myObject = playerRef;

	rightCommand = new RightCommand();
	leftCommand = new LeftCommand();
	upCommand = new UpCommand();
	downCommand = new DownCommand();
}

PlayerController::~PlayerController()
{
	thePlayer = NULL;
	delete rightCommand;
	delete leftCommand;
	delete upCommand;
	delete downCommand;
}

void PlayerController::Update(float timeElapsed)
{

}

void PlayerController::handleInput(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN  && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
			case RIGHT_KEY:
				rightCommand->Execute(myObject);
				break;
			case LEFT_KEY:
				leftCommand->Execute(myObject);
				break;
			case UP_KEY:
				upCommand->Execute(myObject);
				break;
			case DOWN_KEY:
				downCommand->Execute(myObject);
				break;
		}
	}
	else if (e.type == SDL_KEYUP  && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
			case RIGHT_KEY:
				rightCommand->ExecuteRelease(myObject);
				break;
			case LEFT_KEY:
				leftCommand->ExecuteRelease(myObject);
				break;
			case UP_KEY:
				upCommand->ExecuteRelease(myObject);
				break;
			case DOWN_KEY:
				downCommand->ExecuteRelease(myObject);
				break;
		}
	}
}

