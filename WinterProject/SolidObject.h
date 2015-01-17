#ifndef SOLIDOBJECT_H
#define SOLIDOBJECT_H

#include "Collision.h"

class SolidObject : public Collision
{
	public: 
		SolidObject(GameObject* theObject);
};

#endif SOLIDOBJECT_H