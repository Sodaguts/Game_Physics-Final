#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Vector2D.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "LTexture.h"


//Screen dimension constants
const int SCREEN_WIDTH = 630;
const int SCREEN_HEIGHT = 480;

const std::string IMAGE_FILENAME = "Images/Image_47.bmp";

bool init();
bool loadMedia();
void close();

SDL_Renderer* getRenderer();

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
//SDL_Surface* gImage = NULL;
extern SDL_Renderer* gRenderer = NULL;

std::string printCurrentVector(Vector2D vec);
SDL_Renderer* getRenderer() 
{
	return gRenderer;
}


bool init()
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

bool loadMedia()
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

void close()
{
	//Deallocate surface
	//SDL_FreeSurface(gImage);
	//gImage = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL
	SDL_Quit();
}

int main(int argc, char* args[])
{
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Vector2D testVector(1,1);
		//load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool quit = false;
			SDL_Event e;
			while (quit == false) 
			{ 
				while (SDL_PollEvent(&e)) 
				{ 
					if (e.type == SDL_QUIT) quit = true; 
					else if(e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym) 
						{
							case SDLK_SPACE:
								printf("SPACE PRESSED\n");
								break;
							case SDLK_UP:
								printf("UP PRESSED ");
								testVector.y = testVector.y + 1;
								std::cout << printCurrentVector(testVector);
								break;
							case SDLK_DOWN:
								printf("DOWN PRESSED ");
								testVector.y = testVector.y - 1;
								std::cout << printCurrentVector(testVector);
								break;
							case SDLK_RIGHT:
								printf("RIGHT PRESSED ");
								testVector.x = testVector.x + 1;
								std::cout << printCurrentVector(testVector);
								break;
							case SDLK_LEFT:
								printf("LEFT PRESSED ");
								testVector.x = testVector.x - 1;
								std::cout << printCurrentVector(testVector);
								break;
						}
					}
					//Clear Screen
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);

					//Draw Red Quad
					SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
					SDL_RenderFillRect(gRenderer, &fillRect);
				} 
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	close();
	return 0;
}

std::string printCurrentVector(Vector2D vec) 
{
	std::string output = "(" + std::to_string(vec.x) + "," + std::to_string(vec.y) + ")\n";
	return output;
}
