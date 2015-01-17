#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <Windows.h>
#include "Sprite.h"
#include "GameController.h"
#include "Player.h"
#include "PlayerController.h"
#include <iostream>
#include <sstream>
#include <string>
#include <list>

using namespace std;

Player* Player::instance;

Player* Player::Instance()
{
	//if (instance == NULL)
		//instance = new Player();
	return instance;
}

Player::Player(float xPos, float yPos) : GameObject(new Visible(this), new PlayerController(this), new PlayerCollision(this))
{
	width = 64;
	height = 64;
	xPosition = xPos;
	yPosition = yPos;
	instance = this;
	_v->setTexture(GameController::Instance()->loadTexture("Player.png"));
	//add physicsBody
	_p = new PhysicsBody(this);
	myComponents.push_back(_p);

	GameController::Instance()->addToGameObjectList(this);
	objectName = "Player";
	
}

Player::~Player()
{
	instance = NULL;
}