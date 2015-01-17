#ifndef COLLISION_H
#define COLLISION_H

using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include "Component.h"
#include <string>
#include <list>
#include "Vector2.h"


class Collision : public Component
{
	public:
		Collision();
		Collision(GameObject* theObject);
		Vector2 topPoint();
		Vector2 bottomPoint();
		Vector2 leftPoint();
		Vector2 rightPoint();
		Vector2 topRightPoint();
		Vector2 topLeftPoint();
		Vector2 bottomRightPoint();
		Vector2 bottomLeftPoint();
		virtual bool CheckCollision();
		bool PointIntersect(Vector2 point);
		bool IsSolid() { return solid; }
		bool AABBIntersect(SDL_Rect theRect);
	protected:
		bool RectIntersect(SDL_Rect theRect);
		bool solid;
};

#endif COLLISION_H