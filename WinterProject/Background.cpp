#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <Windows.h>
#include "Sprite.h"
#include "GameController.h"
#include "Background.h"
#include <iostream>
#include <sstream>
#include <string>

Background::Background()
{
	_v = new Visible(this);
	_v->setTexture(GameController::Instance()->loadTexture("Background.png"));

	_t = new Tickable(this);
	_c = new NonSolidObject(this);
	myComponents.push_back(_v);
	myComponents.push_back(_t);
	myComponents.push_back(_c);

	objectName = "Background";
	height = 480;
	width = 640;
	xPosition = 0;
	yPosition = 0;

	GameController::Instance()->addToGameObjectList(this);
}
