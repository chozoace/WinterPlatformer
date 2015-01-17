#include "Visible.h"

Visible::Visible(GameObject *theObject)
{
	myObject = theObject;
	componentName = "VisibleComponent";
}

void Visible::Draw(SDL_Renderer* theRenderer)
{
	destRect = myObject->GetDestRect();
	SDL_RenderCopy(theRenderer, myTexture, NULL, &destRect);
}