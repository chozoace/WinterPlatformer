#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <Windows.h>
#include "Sprite.h"
#include "Wall.h"
#include "GameObject.h"
#include "PlayerController.h"
#include <iostream>
#include <sstream>
#include <string>
#include <list>

using namespace std;
class PlayerController; 

class GameController
{
	int id;
	public:
		GameController();
		~GameController();
		bool Initialize();
		SDL_Texture* loadTexture(std::string path);
		void Update(float timeElapsed);
		void handleInput(SDL_Event& e);
		static GameController* Instance();
		void CreatePlayerAt(int x, int y);
		void Draw();
		void addToGameObjectList(GameObject *theObject);
		void removeFromGameObjectList(GameObject *theObject);
		SDL_Event& getCurrentEvent();
};

#endif