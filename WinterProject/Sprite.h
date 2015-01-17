#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <SDL_image.h>

class Sprite
{
	public:
		Sprite();
		virtual ~Sprite();
		Sprite(SDL_Texture* tex);
		virtual void Update();
		virtual void Draw(SDL_Renderer* theRenderer);
		virtual void close();
		SDL_Rect getBoundingBox();
	protected:
		virtual bool loadContent();
		SDL_Texture* myTexture = NULL;
		SDL_Rect boundingBox;
		int width;
		int height;
		float XPosition;
		float YPosition;

};

#endif