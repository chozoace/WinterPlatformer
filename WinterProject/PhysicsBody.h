#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H

#include "Component.h"
#include "Vector2.h"

class PhysicsBody : public Component
{
	public:
		//public stuff
		PhysicsBody(GameObject* theObject);
		~PhysicsBody();
		void Update(float timeElapsed);
		float getXVelocity(){ return velocity.x; }
		float getYVelocity(){ return velocity.y; }
		float getMaxMoveSpeed() { return maxMoveSpeed; }
		float getJumpSpeed() { return jumpSpeed; }
		void setXVelocity(float val) { velocity.x = val; }
		void setYVelocity(float val) { velocity.y = val; }
	protected:
		float gravity;
		float mass;
		float maxFallSpeed;
		float maxMoveSpeed;
		float jumpSpeed;
		bool grounded;
		Vector2 velocity;
		Vector2 acceleration;

};

#endif PHYSICSBODY_H