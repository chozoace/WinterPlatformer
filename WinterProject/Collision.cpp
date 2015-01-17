#include "Collision.h"
#include "GameObject.h"

Collision::Collision()
{

}

Collision::Collision(GameObject* theObject)
{
	myObject = theObject;
	componentName = "BaseCollision";
}

Vector2 Collision::topPoint()
{
	Vector2 top;
	top.x = (float)myObject->getXPos() + (myObject->getWidth() / 2);
	top.y = (float)myObject->getYPos();
	return top;
};
Vector2 Collision::bottomPoint()
{
	Vector2 bottom;
	bottom.x = (float)myObject->getXPos() + (myObject->getWidth() / 2);
	bottom.y = (float)myObject->getYPos() + myObject->getHeight();
	return bottom;
};
Vector2 Collision::leftPoint()
{
	Vector2 left;
	left.x = (float)myObject->getXPos();
	left.y = (float)myObject->getYPos() + (myObject->getHeight() / 2);
	return left;
};
Vector2 Collision::rightPoint()
{
	Vector2 right;
	right.x = (float)myObject->getXPos() + myObject->getWidth();
	right.y = (float)myObject->getYPos() + (myObject->getHeight() / 2);
	return right;
};
Vector2 Collision::topRightPoint()
{
	Vector2 topRight;
	topRight.x = (float)myObject->getXPos() + myObject->getWidth();
	topRight.y = (float)myObject->getYPos();
	return topRight;
};
Vector2 Collision::topLeftPoint()
{
	Vector2 topLeft;
	topLeft.x = (float)myObject->getXPos();
	topLeft.y = (float)myObject->getYPos();
	return topLeft;
};
Vector2 Collision::bottomRightPoint()
{
	Vector2 bottomRight;
	bottomRight.x = (float)myObject->getXPos() + myObject->getWidth();
	bottomRight.y = (float)myObject->getYPos() + myObject->getHeight();
	return bottomRight;
};
Vector2 Collision::bottomLeftPoint()
{
	Vector2 bottomLeft;
	bottomLeft.x = (float)myObject->getXPos();
	bottomLeft.y = (float)myObject->getYPos() + myObject->getHeight();
	//printf("in function, x is: %f\n", bottomLeft.x);
	//printf("in function, y is: %f\n", bottomLeft.y);
	return bottomLeft;
};

bool Collision::CheckCollision()
{
	//detects collision
	return false;
}

bool Collision::PointIntersect(Vector2 point)
{
	SDL_Rect theRect = myObject->GetDestRect();
	//printf("Point : x: %f y: %f\n", point.x, point.y);
	//printf("Rect: x: %d y: %d w: %d h: %d\n", theRect.x, theRect.y, theRect.w, theRect.h);
	if (point.x >= theRect.x && point.x <= (theRect.x + theRect.w))
	{
		if (point.y >= theRect.y && point.y <= (theRect.y + theRect.h))
		{
			return true;
		}
	}
	return false;
}

bool Collision::RectIntersect(SDL_Rect theRect)
{

	return false;
}

bool Collision::AABBIntersect(SDL_Rect theRect)
{
	//if right edge 1 less than left edge 2
	//if right edge 2 is less than left edge 1
	//if top 1 is greater than bottom 2
	//if top 2 is greater than bottom 1

	//if any of that is true, I get false, there is NO collision
	//If they are all false, I get true, there is collision
	//printf("2 player rect data: \n x: %d y: %d h: %d w: %d\n", theRect.x, theRect.y, theRect.h + theRect.y, theRect.w + theRect.x);
	//printf("2 dest rect/wall data: \n x: %d y: %d h: %d w: %d\n", (int)leftPoint().x, (int)topPoint().y, (int)bottomPoint().y, (int)rightPoint().x);
	return !((int)rightPoint().x < theRect.x || theRect.x + theRect.w < (int)leftPoint().x
		|| (int)topPoint().y > theRect.y + theRect.h || theRect.y > (int)bottomPoint().y);
}