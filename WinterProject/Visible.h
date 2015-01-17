#ifndef VISIBLE_H
#define VISIBLE_H

#include "Visibility.h"
#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Visible : public Visibility
{
	public:
		Visible(GameObject *theObject);
		virtual void Draw(SDL_Renderer* theRenderer);
	protected:
		SDL_Rect sourceRect;
		SDL_Rect destRect;
};

#endif VISIBLE_H