#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "Wall.h"

class Platform : public Wall
{
	public:
		Platform();
		virtual void Update();
		virtual void Draw(SDL_Renderer* theRenderer);
	protected:
		virtual bool loadContent();
};

#endif PLATFORM_H