#include "Wall.h"
#include "GameController.h"

Wall::Wall()
{

}

Wall::Wall(float xPos, float yPos, int theWidth, int theHeight, int id, string theName)
{
	xPosition = xPos;
	yPosition = yPos;
	width = theWidth;
	height = theHeight;
	imageId = id;
	objectName = theName;
	_v = new Visible(this);
	switch (imageId)
	{
		case 1:
			_v->setTexture(GameController::Instance()->loadTexture("Platform.png"));
			objectName = "Wall";
			isSlope = false;
			isSlopeHelp = false;
			break;
		case 3: 
			_v->setTexture(GameController::Instance()->loadTexture("45Slope.png"));
			objectName = "SlopeWallLeft";
			slopeWidth = 32;
			slopeHeight = 32;
			slopeDirection = -1;
			isSlope = true;
			isSlopeHelp = false;
			break;
		case 4:
			_v->setTexture(GameController::Instance()->loadTexture("45Slope2.png"));
			objectName = "SlopeWallRight";
			slopeWidth = 32;
			slopeHeight = 32;
			slopeDirection = 1;
			isSlope = true;
			isSlopeHelp = false;
			break;
		case 5:
			_v->setTexture(GameController::Instance()->loadTexture("Platform.png"));
			objectName = "Wall";
			isSlope = false;
			isSlopeHelp = true;
	}
	_t = new Tickable(this);
	_c = new SolidObject(this);
	myComponents.push_back(_v);
	myComponents.push_back(_t);
	myComponents.push_back(_c);
}

Wall::~Wall()
{

}


