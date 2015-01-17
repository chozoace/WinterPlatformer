#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "GameObject.h"
#include "Component.h"
#include "PlayerCollision.h"
#include "PhysicsBody.h"
#include "Vector2.h"

class Player : public GameObject
{
	public:
		//Player();
		Player(float xPos, float yPos);
		virtual ~Player();
		static Player* Instance();
		
		void setRightMove(bool val){ movingRight = val; }
		void setLeftMove(bool val){ movingLeft = val; }
		void setUpMove(bool val){ movingUp = val; }
		void setDownMove(bool val){ movingDown = val; }
		bool getRightMove(){ return movingRight; }
		bool getLeftMove(){ return movingLeft; }
		bool getUpMove(){ return movingUp; }
		bool getDownMove(){ return movingDown; }

	protected:
		static Player* instance;
		float maxVelocity = .1f;
		bool movingLeft;
		bool movingRight;
		bool movingUp;
		bool movingDown;
};

#endif PLAYER_H