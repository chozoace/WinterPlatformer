#include "NonSolidObject.h"

NonSolidObject::NonSolidObject(GameObject* theObject)
{
	myObject = theObject;
	solid = false;
	componentName = "NonSolidObjectComponent";
}