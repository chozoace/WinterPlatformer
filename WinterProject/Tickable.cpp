#include "Tickable.h"
#include "GameObject.h"


Tickable::Tickable()
{

}

Tickable::Tickable(GameObject *theObject)
{
	myObject = theObject;
	componentName = "BaseTickable";
}

Tickable::~Tickable()
{

}

void Tickable::Update(float timeElapsed)
{

}