#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <Windows.h>
#include "GameController.h"
#include "Component.h"
#include "GameObject.h"
#include <iostream>
#include <sstream>
#include <string>
#include <list>

SDL_Rect GameObject::GetDestRect()
{
	SDL_Rect result;
	result.x = (int)xPosition;
	result.y = (int)yPosition;
	result.w = width;
	result.h = height;
	return result;
}

GameObject::GameObject()
{
	//default
}

GameObject::~GameObject()
{
	delete _v;
	delete _c;
	delete _t;
	if (_p != NULL)
		delete _p;
	while (!myComponents.empty())
	{
		//Does this actually destroy the components?
		//Does it call it's destructor?
		myComponents.back() = NULL;
		myComponents.pop_back();
	}
}

GameObject::GameObject(Visibility *v, Tickable *t, Collision *c)
{
	_v = v;
	_t = t;
	_c = c;
	myComponents.push_back(v);
	myComponents.push_back(t);
	myComponents.push_back(c);

	/*list<Component*>::iterator iter;
	for (iter = myComponents.begin(); iter != myComponents.end(); iter++)
	{
		printf("%s\n", (*iter)->GetComponentName().c_str());
	}*/
}

void GameObject::Update(float timeElapsed)
{
	if (_p != NULL)
	{
		_p->Update(timeElapsed);
	}
	_t->Update(timeElapsed);
}

void GameObject::Draw(SDL_Renderer* theRenderer)
{
	_v->Draw(theRenderer);
}

bool GameObject::CheckCollision()
{
	_c->CheckCollision();
	return false;
}

void GameObject::AddComponent(Component *theComponent)
{
	bool canAdd = true;
	list<Component*>::iterator it;
	for (it = myComponents.begin(); it != myComponents.end(); it++)
	{
		if (!((*it)->GetComponentName().compare(theComponent->GetComponentName())))
		{
			canAdd = false;
		}
	}
	if (canAdd)
		myComponents.push_back(theComponent);
}

void GameObject::RemoveComponent(Component *theComponent)
{
	
}