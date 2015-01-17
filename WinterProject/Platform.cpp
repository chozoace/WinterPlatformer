#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <Windows.h>
#include "Sprite.h"
#include "GameController.h"
#include "Platform.h"
#include <iostream>
#include <sstream>
#include <string>

Platform::Platform()
{
	/*width = 300;
	height = 40;
	boundingBox.x = 100;
	boundingBox.y = 250;
	boundingBox.w = 300;
	boundingBox.h = 40;
	loadContent();*/
}

bool Platform::loadContent()
{
	/*bool success = true;

	myTexture = GameController::Instance()->loadTexture("Platform.png");
	GameController::Instance()->addToSpriteList(this);
	GameController::Instance()->addToWallList(this);

	return success;*/
	return false;
}

void Platform::Update()
{

}

void Platform::Draw(SDL_Renderer* theRenderer)
{
	//SDL_RenderCopy(theRenderer, myTexture, NULL, &boundingBox);
}