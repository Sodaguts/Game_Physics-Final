#include "game.h"
#include <iostream>
#include "Particle.h"
Game* Game::game = nullptr;

Game* Game::getInstance() 
{
	return game;
}

void Game::createInstance() 
{
	game = new Game();
}

Game::~Game() 
{
	close();
}

bool Game::init(const int SCREEN_WIDTH, const int SCREEN_HEIGHT) 
{
	bool success = true;
	SCREEN_W = SCREEN_WIDTH;
	SCREEN_H = SCREEN_HEIGHT;

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

	return success;
}

bool Game::setFont(std::string filename, float size) 
{
	bool success = true;
	gFont = TTF_OpenFont(filename.c_str(), size);
	if (gFont == NULL) 
	{
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	return success;
}

void Game::createParticle(Vector2D position) 
{
	Vector2D spawnPos = Vector2D(position.x - 16, position.y - 16);
	Particle* p = new Particle(spawnPos);
	particles.push_back(p);
}

void Game::close() 
{

	for (auto i = 0; i < particles.size(); i++) 
	{
		delete particles[i];
		particles[i] = nullptr;
	}

	TTF_CloseFont(gFont);
	gFont = NULL;

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}