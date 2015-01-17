#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include "Component.h"
#include <list>
#include "Visibility.h"
#include "Collision.h"
#include "Tickable.h"
#include "Visible.h"
#include "SolidObject.h"
#include <string>
#include <typeinfo>

#include "PhysicsBody.h"

class GameObject
{
	public:
		GameObject();
		virtual ~GameObject();
		GameObject(Visibility *v, Tickable *t, Collision *c);
		virtual void Update(float timeElapsed);
		virtual void Draw(SDL_Renderer* theRenderer);
		virtual bool CheckCollision();
		void AddComponent(Component *theComponent);
		void RemoveComponent(Component *theComponent);
		template<class T>
		T* GetComponent()
		{
			list<Component*>::iterator iter;
			for (iter = myComponents.begin(); iter != myComponents.end(); iter++)
			{
				T* temp = dynamic_cast<T*>(*iter);
				if (temp != NULL)
				{
					return temp;
				}
			}
			return NULL;
		}
		SDL_Rect GetDestRect();

		void setXPos(float newPos){ xPosition = newPos; }
		void setYPos(float newPos){ yPosition = newPos; }
		float getXPos(){ return xPosition; }
		float getYPos(){ return yPosition; }
		int getWidth(){ return width; }
		int getHeight(){ return height; }
	protected:
		Visibility *_v;
		Tickable *_t;
		Collision *_c;
		PhysicsBody *_p = NULL;
		float xPosition;
		float yPosition;
		int width;
		int height;
		string objectName = "DefaultName";
		list<Component*> myComponents;
};

#endif GAMEOBJECT_H