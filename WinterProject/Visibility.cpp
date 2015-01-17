#include "Visibility.h"

Visibility::Visibility()
{

}

Visibility::~Visibility()
{
	SDL_DestroyTexture(myTexture);
	myTexture = NULL;
}

void Visibility::Draw(SDL_Renderer* theRenderer)
{

}

void Visibility::setTexture(SDL_Texture* theTex)
{
	myTexture = theTex;
}

SDL_Texture* Visibility::getTexture()
{
	return myTexture;
}