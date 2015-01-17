#include "PlayerCollision.h"
#include "LevelConstructor.h"

PlayerCollision::PlayerCollision(GameObject* theObject)
{
	myObject = theObject;
	componentName = "PlayerCollisionComponent";
	solid = true;
	Vector2 temp = bottomLeftPoint();
	//printf("x: %d y: %d\n", temp.x, temp.y);
}

PlayerCollision::~PlayerCollision()
{
	
}

bool PlayerCollision::CheckCollision(Vector2 collisionPoint, bool cornerPoint)
{
	list<Wall*> *wallList = LevelConstructor::Instance()->getWallList();
	Vector2 temp = bottomLeftPoint();
	//printf("x: %f y: %f\n", temp.x, temp.y);

	//change this loop to not check whole list
	list<Wall*>::iterator iter;
	for (iter = wallList->begin(); iter != wallList->end(); iter++)
	{
		Collision *collisionComponent = NULL;
		collisionComponent = (*iter)->GetComponent<Collision>();
		
		if (collisionComponent != NULL)
		{
			if (collisionComponent->PointIntersect(collisionPoint))
			{
				if (collisionComponent->IsSolid())
				{
					//if slope block, ignore collision
					//find a way to check what "collisionPoint" is
					if ((*iter)->getID() == 3 || (*iter)->getID() == 5)
					{
						if (cornerPoint)
						{		
							collidingWall = (*iter);
							return true;
						}
						else
						{
							collidingWall = (*iter);
							return false;
						}
					}
					else
					{
						collidingWall = (*iter);
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool PlayerCollision::CheckAABBCollision(SDL_Rect theRect)
{
	list<Wall*> *wallList = LevelConstructor::Instance()->getWallList();

	list<Wall*>::iterator iter;
	for (iter = wallList->begin(); iter != wallList->end(); iter++)
	{
		Collision *collisionComponent = NULL;
		collisionComponent = (*iter)->GetComponent<Collision>();

		if (collisionComponent != NULL)
		{
			//printf("1 dest rect data: \n x: %d y: %d h: %d w: %d\n", (*iter)->GetDestRect().x, (*iter)->GetDestRect().y, (*iter)->GetDestRect().h + (*iter)->GetDestRect().y, (*iter)->GetDestRect().w + (*iter)->GetDestRect().x);
			//printf("1 player data: \n x: %f y: %f h: %f w: %f\n", myObject->getXPos(), myObject->getYPos(), bottomPoint().y, rightPoint().x);
			if (collisionComponent->AABBIntersect(theRect) && collisionComponent->IsSolid())
			{
				//Collision
				return true;
			}
		}
	}
	return false;
}
