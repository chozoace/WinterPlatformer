#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <Windows.h>
#include "GameController.h"
#include "Background.h"
#include "Platform.h"
#include "Sprite.h"
#include "Player.h"
#include "GameObject.h"
#include "Component.h"
#include "LevelConstructor.h"
#include <iostream>
#include <sstream>
#include <string>
#include <list>

using namespace std;

const int screenWidth = 640;
const int screenHeight = 480;

bool loadContent();
bool initialized;

//pointer to the window which we will render to
SDL_Window* gWindow = NULL;
//pointer to the window renderer
SDL_Renderer* gRenderer = NULL;
//pointer to the texture
SDL_Texture* gTexture = NULL;
static GameController* instance = NULL;

list<GameObject*> gameObjectList;
Background* theBackground = NULL;
Platform* thePlatform = NULL;
Player* player = NULL;
LevelConstructor* levelConstructor = NULL;

SDL_Event currentEvent;
PlayerController* playerControllerComponent = NULL;

GameController* GameController::Instance()
{
	if (instance == NULL)
		instance = new GameController();
	return instance;
}

GameController::GameController()
{
	initialized = false;
	if (!Initialize())
	{
		printf("Failed to Initialize GameController\n");
	}
	else
	{
		initialized = true;
		//Add things to Level
		theBackground = new Background();
		levelConstructor = new LevelConstructor();
	}
}

void GameController::CreatePlayerAt(int x, int y)
{
	player = new Player((float)x, (float)y);
	playerControllerComponent = player->GetComponent<PlayerController>();
	Tickable *test = NULL;
	/*test = player->GetComponent<Tickable>();
	if (test != NULL)
		printf("success\n");*/
}

GameController::~GameController()
{
	delete theBackground;
	delete thePlatform;
	delete player;
	delete levelConstructor;
	playerControllerComponent = NULL;

	while (!gameObjectList.empty())
	{
		gameObjectList.back() = NULL;
		gameObjectList.pop_back();
	}

	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyTexture(gTexture);
	instance = NULL;
	gTexture = NULL;
	gRenderer = NULL;
	gWindow = NULL;
}

bool GameController::Initialize()
{
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texutre filtering not enabled!");
		}

		//create window
		gWindow = SDL_CreateWindow("Winter Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//create renderer
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				instance = this;
			}
		}
	}

	return success;
}

SDL_Texture* GameController::loadTexture(std::string path)
{
	SDL_Texture* newTexture = NULL;

	//load image from path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void GameController::Update(float timeElapsed)
{
	if (initialized)
	{
		list<GameObject*>::iterator iter;
		for (iter = gameObjectList.begin(); iter != gameObjectList.end(); iter++)
		{
			(*iter)->Update(timeElapsed);
		}
	}
}

void GameController::handleInput(SDL_Event& e)
{
	currentEvent = e;
	if (player != NULL)
	{
		playerControllerComponent->handleInput(e);
	}
}

SDL_Event& GameController::getCurrentEvent()
{
	return currentEvent;
}

void GameController::addToGameObjectList(GameObject *theObject)
{
	gameObjectList.push_back(theObject);
}

void GameController::removeFromGameObjectList(GameObject *theObject)
{

}

void GameController::Draw()
{
	SDL_RenderClear(gRenderer);
	
	list<GameObject*>::iterator iter;
	for (iter = gameObjectList.begin(); iter != gameObjectList.end(); iter++)
	{
		(*iter)->Draw(gRenderer);
	}

	SDL_RenderPresent(gRenderer);
}