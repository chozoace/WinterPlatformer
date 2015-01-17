#ifndef NONSOLIDOBJECT_H
#define NONSOLIDOBJECT_H

#include "Collision.h"

class NonSolidObject : public Collision
{
public:
	NonSolidObject(GameObject* theObject);
};

#endif NONSOLIDOBJECT_H