#ifndef VISIBILITY_H
#define VISIBILITY_H

using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include "Component.h"
#include <string>

class Visibility : public Component
{
	public:
		Visibility();
		virtual ~Visibility();
		virtual void Draw(SDL_Renderer* theRenderer);
		void setTexture(SDL_Texture* theTex);
		SDL_Texture* getTexture();
	protected:
		SDL_Rect sourceRect;
		SDL_Rect destRect;
		SDL_Texture* myTexture = NULL;
};

#endif VISIBILITY_H