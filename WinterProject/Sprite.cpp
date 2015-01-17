#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <Windows.h>
#include "Sprite.h"
#include "GameController.h"
#include <iostream>
#include <sstream>
#include <string>

Sprite::Sprite()
{

}

Sprite::~Sprite()
{
	SDL_DestroyTexture(myTexture);
	myTexture = NULL;
}

bool Sprite::loadContent()
{
	bool success = true;

	return success;
}

void Sprite::Update()
{

}

void Sprite::Draw(SDL_Renderer* theRenderer)
{
	//Render texture to screen 
	SDL_RenderCopy(theRenderer, myTexture, NULL, NULL);
}

SDL_Rect Sprite::getBoundingBox()
{
	return boundingBox;
}

void Sprite::close()
{
	
}