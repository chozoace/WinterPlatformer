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

Component::Component()
{
	componentName = "defaultComponent";
}

Component::~Component()
{
	myObject = NULL;
}

void Component::Update()
{

}

void Component::Destroy()
{

}

string Component::GetComponentName()
{
	return componentName;
}

Component* Component::GetComponent()
{
	return this;
}