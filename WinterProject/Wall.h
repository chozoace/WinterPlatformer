#ifndef WALL_H
#define WALL_H

#include "GameObject.h"

class Wall : public GameObject
{
	public:
		Wall();
		Wall(float xPos, float yPos, int theWidth, int theHeight, int id = 0, string theName = "Wall");
		~Wall();
		int getID(){ return imageId; };
		int getSlopeHeight(){ return slopeHeight; };
		int getSlopeWidth(){ return slopeWidth; };
		int getSlopeDirection() { return slopeDirection; };
		bool IsSlope() { return isSlope; }
		bool IsSlopeHelp() { return isSlopeHelp; }
	private:
		int imageId;
		int slopeWidth = 0;
		int slopeHeight = 0;
		int slopeDirection = 0;
		bool isSlope;
		bool isSlopeHelp;
};

#endif WALL_H