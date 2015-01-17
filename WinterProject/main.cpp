#include <SDL.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "main.h"
#include "GameController.h"
#include <iostream>
#include <sstream>

int main(int argc, char* args[])
{
	//main loop
	bool running = true;
	SDL_Event e;
	GameController gameController;
	float lastTime = (((float)clock()) / CLOCKS_PER_SEC);
	float minTimeStep = (1 / 60);

	while (running)
	{
		float current = (((float)clock()) / CLOCKS_PER_SEC);
		float elapsed = (current - lastTime);
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				printf("quitting\n");
				running = false;
			}
			else
				gameController.handleInput(e);
		}
		gameController.Update(elapsed);
		gameController.Draw();
		lastTime = current;
		//if elapsed < 1/max fps, sleep
		if (elapsed < minTimeStep)
		{
			Sleep((minTimeStep - elapsed)*1000);
		}

	}
	printf("out of while\n");

	return 0;
}