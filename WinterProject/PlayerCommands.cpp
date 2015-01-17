#include "Command.h"
#include "Player.h"
#include "PhysicsBody.h"

void RightCommand::rightMove(GameObject* theObject)
{	
	Player::Instance()->setRightMove(true);

	PhysicsBody *physComponent = NULL;
	physComponent = theObject->GetComponent<PhysicsBody>();
	if (physComponent != NULL)
	{
		physComponent->setXVelocity(physComponent->getXVelocity() + physComponent->getMaxMoveSpeed());
	}
}

void RightCommand::rightMoveRelease(GameObject* theObject)
{
	Player::Instance()->setRightMove(false);

	PhysicsBody *physComponent = NULL;
	physComponent = theObject->GetComponent<PhysicsBody>();
	if (physComponent != NULL)
	{
		physComponent->setXVelocity(physComponent->getXVelocity() - physComponent->getMaxMoveSpeed());
	}
}

void LeftCommand::leftMove(GameObject* theObject)
{
	Player::Instance()->setLeftMove(true);

	PhysicsBody *physComponent = NULL;
	physComponent = theObject->GetComponent<PhysicsBody>();
	if (physComponent != NULL)
	{
		physComponent->setXVelocity(physComponent->getXVelocity() - physComponent->getMaxMoveSpeed());
	}
}

void LeftCommand::leftMoveRelease(GameObject* theObject)
{
	Player::Instance()->setLeftMove(false);

	PhysicsBody *physComponent = NULL;
	physComponent = theObject->GetComponent<PhysicsBody>();
	if (physComponent != NULL)
	{
		physComponent->setXVelocity(physComponent->getXVelocity() + physComponent->getMaxMoveSpeed());
	}
}

void UpCommand::upMove(GameObject* theObject)
{
	Player::Instance()->setUpMove(true);

	PlayerCollision *collisionComponent = theObject->GetComponent<PlayerCollision>();
	PhysicsBody *physComponent = NULL;
	physComponent = theObject->GetComponent<PhysicsBody>();
	if (physComponent != NULL)
	{
		if (collisionComponent->CheckCollision(collisionComponent->bottomPoint(), false) || collisionComponent->CheckCollision(collisionComponent->bottomLeftPoint(), true)
			|| collisionComponent->CheckCollision(collisionComponent->bottomRightPoint(), true))
		{
			theObject->setYPos(theObject->getYPos() - 1);
			physComponent->setYVelocity(-physComponent->getJumpSpeed());
		}
	}
}

void UpCommand::upMoveRelease(GameObject* theObject)
{
	Player::Instance()->setUpMove(false);
}

void DownCommand::downMove(GameObject* theObject)
{
	Player::Instance()->setDownMove(true);
}

void DownCommand::downMoveRelease(GameObject* theObject)
{
	Player::Instance()->setDownMove(false);
}