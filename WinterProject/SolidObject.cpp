#include "SolidObject.h"

SolidObject::SolidObject(GameObject* theObject)
{
	myObject = theObject;
	solid = true;
	componentName = "SolidObjectComponent";
}