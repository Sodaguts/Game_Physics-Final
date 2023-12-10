#include "game.h"
#include <iostream>

//Game::Game(const int SCREEN_WIDTH, const int SCREEN_HEIGHT) 
//{
//	init(SCREEN_WIDTH, SCREEN_HEIGHT);
//}
Game* Game::getInstance() 
{
	if (game == NULL) 
	{
		game = new Game();
	}
	return game;
}

Game::~Game() 
{
	close();
}

bool Game::init(const int SCREEN_WIDTH, const int SCREEN_HEIGHT) 
{
	bool success = true;

	//initialize sdl
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Game Physics Final", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_ERROR: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			//gScreenSurface = SDL_GetWindowSurface(gWindow);
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL_ERROR: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
	}
	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;

	/*gImage = SDL_LoadBMP("Images/Image_47.bmp");
	if (gImage == NULL)
	{
		printf("Unable to load image! SDL_ERROR: %s\n", "Images/Image_47.bmp", SDL_GetError());
		success = false;
	}*/

	return success;
}

void Game::close() 
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL
	SDL_Quit();
}