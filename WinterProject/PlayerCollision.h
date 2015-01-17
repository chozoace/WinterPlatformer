#ifndef PLAYERCOLLISION_H
#define PLAYERCOLLSION_H

#include "Collision.h"
#include "GameObject.h"
#include "Wall.h"

class PlayerCollision : public Collision
{
	public:
		PlayerCollision(GameObject* theObject);
		~PlayerCollision();
		bool CheckCollision(Vector2 collisionPoint, bool cornerPoint);
		bool CheckAABBCollision(SDL_Rect theRect);
		Wall* getCollidingWall(){ return collidingWall; }
	protected:
		Wall *collidingWall;
};

#endif PLAYERCOLLISION_H