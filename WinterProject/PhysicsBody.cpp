#include "PhysicsBody.h"
#include "GameObject.h"
#include "PlayerCollision.h"

PhysicsBody::PhysicsBody(GameObject* theObject)
{
	myObject = theObject;
	mass = 1.0f;
	gravity = 6000.0f;
	maxFallSpeed = 10000.0f;
	maxMoveSpeed = 150.0f;
	jumpSpeed = 1500.0f;
	velocity.x = 0;
	velocity.y = 0;
	grounded = false;

	printf("created\n");
}

PhysicsBody::~PhysicsBody()
{
	//never called
	//is it being destroyed?
	printf("destroyed\n");
}

void PhysicsBody::Update(float timeElapsed)
{
	float currentXPos = myObject->getXPos();
	float currentYPos = myObject->getYPos();
	PlayerCollision *collisionComponent = myObject->GetComponent<PlayerCollision>();
	bool xCollision = false;
	
	//Apply Force
	velocity.y += (gravity * timeElapsed);
	if (!xCollision)
		myObject->setXPos(currentXPos += velocity.x * timeElapsed);
	myObject->setYPos(currentYPos += velocity.y * timeElapsed);

	
	//Check Collision (AABB)
	if(collisionComponent->CheckAABBCollision(myObject->GetDestRect()))
	{
		if(velocity.y < 0)
		{
			//UPPER COLLISION
			if (collisionComponent->CheckCollision(collisionComponent->topPoint(), false) || collisionComponent->CheckCollision(collisionComponent->topRightPoint(), false)
				|| collisionComponent->CheckCollision(collisionComponent->topLeftPoint(), false))
			{
				if (!collisionComponent->CheckCollision(collisionComponent->rightPoint(), false) && !collisionComponent->CheckCollision(collisionComponent->leftPoint(), false))
				{
					Wall *collidingWall = collisionComponent->getCollidingWall();
					myObject->setYPos(collidingWall->getYPos() + collidingWall->getHeight());
					velocity.y = 0;
				}
				else if (collisionComponent->CheckCollision(collisionComponent->topPoint(), false))
				{
					Wall *collidingWall = collisionComponent->getCollidingWall();
					myObject->setYPos(collidingWall->getYPos() + collidingWall->getHeight());
					velocity.y = 0;
				}
			}
		}
		else if(velocity.y >= 0)
		{
			//FALLING COLLISION
			if (collisionComponent->CheckCollision(collisionComponent->bottomPoint(), false) || collisionComponent->CheckCollision(collisionComponent->bottomRightPoint(), false)
				|| collisionComponent->CheckCollision(collisionComponent->bottomLeftPoint(), false))
			{
				//If I am not on the edge of the block, I must be on the center so stop me from falling
				if (!collisionComponent->CheckCollision(collisionComponent->rightPoint(), false) && !collisionComponent->CheckCollision(collisionComponent->leftPoint(), false)
					&& !collisionComponent->getCollidingWall()->IsSlope())
				{
					Wall *collidingWall = collisionComponent->getCollidingWall();
					myObject->setYPos(collidingWall->getYPos() - myObject->getHeight());
					velocity.y = 0;
				}
				else if (collisionComponent->CheckCollision(collisionComponent->bottomPoint(), false) && !collisionComponent->getCollidingWall()->IsSlope())
				{
					Wall *collidingWall = collisionComponent->getCollidingWall();
					myObject->setYPos(collidingWall->getYPos() - myObject->getHeight());
					velocity.y = 0;
				}
			}
			//printf("XPos: %d\n", (int)myObject->getXPos());
			//SLOPE COLLISION
			if(collisionComponent->CheckCollision(collisionComponent->bottomLeftPoint(), true) && collisionComponent->getCollidingWall()->IsSlope())
			{
				//if colliding with a slope, readjust y position
				//FIX THE FOLLOWING:
				//I slip between slopes
				//Temporarily fixed by placing "slopehelp blocks under each slope which always move me up
				//player jitters up and down when going down slope
				Wall *theWall = collisionComponent->getCollidingWall();
				int xDistance = (int)myObject->getXPos() - ((int)theWall->getXPos() + (int)theWall->getWidth());
				int resultY = (((int)theWall->getYPos() + theWall->getHeight()) + ((theWall->getSlopeHeight() / theWall->getSlopeWidth()) * xDistance));
				//printf("YPos: %d, ResultY: %d, xDistance: %d, WallY: %d, WallX: %d\n", (int)collisionComponent->bottomLeftPoint().y, resultY, xDistance, (int)theWall->getYPos(), (int)theWall->getXPos());
				if (collisionComponent->bottomLeftPoint().y >= resultY)
				{
					myObject->setYPos(resultY - myObject->getHeight());
					//gravity = 0;
					velocity.y = 0;
					//printf("new YPos: %d\n", (int)myObject->getYPos() + myObject->getHeight()-3);
				}
			}
			else if (collisionComponent->CheckCollision(collisionComponent->bottomLeftPoint(), true) && collisionComponent->getCollidingWall()->IsSlopeHelp())
			{
				printf("slope help collide\n");
				Wall *collidingWall = collisionComponent->getCollidingWall();
				myObject->setYPos(collidingWall->getYPos() - myObject->getHeight() - 1);
				velocity.y = 0;
			}
			else if (collisionComponent->CheckCollision(collisionComponent->bottomRightPoint(), true) && collisionComponent->getCollidingWall()->IsSlope())
			{
				//if colliding with a slope, readjust y position
			}
			else if (collisionComponent->CheckCollision(collisionComponent->bottomRightPoint(), true) && collisionComponent->getCollidingWall()->IsSlopeHelp())
			{
				
			}
		}

		if(velocity.x > 0)
		{
			//RIGHT
			if (collisionComponent->CheckCollision(collisionComponent->rightPoint(), false))
			{
				myObject->setXPos(collisionComponent->getCollidingWall()->getXPos() - myObject->getWidth());
				xCollision = true;
			}
			else if (collisionComponent->CheckCollision(collisionComponent->bottomRightPoint(), false))
			{
				//printf("My Y: %f, Wall Y: %f\n", myObject->getYPos() + myObject->getHeight(), collisionComponent->getCollidingWall()->getYPos());
				if ((myObject->getYPos() + myObject->getHeight()) > collisionComponent->getCollidingWall()->getYPos())
				{
					myObject->setXPos(collisionComponent->getCollidingWall()->getXPos() - myObject->getWidth());
					xCollision = true;
				}
			}
			else if (collisionComponent->CheckCollision(collisionComponent->topRightPoint(), false))
			{
				if (myObject->getYPos() > collisionComponent->getCollidingWall()->getYPos())
				{
					//myObject->setXPos(collisionComponent->getCollidingWall()->getXPos() - myObject->getWidth());
					//xCollision = true;
				}
			}
		}
		else if(velocity.x < 0)
		{
			//LEFT
			if (collisionComponent->CheckCollision(collisionComponent->leftPoint(), false))
			{
				myObject->setXPos(collisionComponent->getCollidingWall()->getXPos() + collisionComponent->getCollidingWall()->getWidth());
				xCollision = true;
			}
			else if (collisionComponent->CheckCollision(collisionComponent->bottomLeftPoint(), false) && !collisionComponent->getCollidingWall()->IsSlopeHelp())
			{
				if ((myObject->getYPos() + myObject->getHeight()) > collisionComponent->getCollidingWall()->getYPos())
				{
					myObject->setXPos(collisionComponent->getCollidingWall()->getXPos() + collisionComponent->getCollidingWall()->getWidth());
					xCollision = true;
				}
			}
			else if (collisionComponent->CheckCollision(collisionComponent->topLeftPoint(), false))
			{
				if (myObject->getYPos() > collisionComponent->getCollidingWall()->getYPos())
				{
					//myObject->setXPos(collisionComponent->getCollidingWall()->getXPos() + collisionComponent->getCollidingWall()->getWidth());
					//xCollision = true;
				}
			}
		}
	}
}

