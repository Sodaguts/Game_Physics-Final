#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Vector2D.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "LTexture.h"
#include "game.h"



//Screen dimension constants
const int SCREEN_WIDTH = 630;
const int SCREEN_HEIGHT = 480;

const std::string IMAGE_FILENAME = "Images/Image_47.bmp";

//bool init();
//bool loadMedia();
//void close();

SDL_Renderer* getRenderer();

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
//SDL_Surface* gImage = NULL;
//extern SDL_Renderer* gRenderer = NULL;

Game* game = new Game(SCREEN_WIDTH, SCREEN_HEIGHT);

std::string printCurrentVector(Vector2D vec);
//SDL_Renderer* getRenderer() 
//{
//	return gRenderer;
//}




int main(int argc, char* args[])
{
	if (!game)
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Vector2D testVector(1,1);
		//load media
		if (!game->loadMedia())
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
					//Process input
					if (e.type == SDL_QUIT) quit = true;
					else if (e.type == SDL_KEYDOWN)
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
					SDL_SetRenderDrawColor(game->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(game->getRenderer());

					//Draw Red Quad
					SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
					SDL_SetRenderDrawColor(game->getRenderer(), 0xFF, 0x00, 0x00, 0xFF);
					SDL_RenderFillRect(game->getRenderer(), &fillRect);
				} 
				SDL_RenderPresent(game->getRenderer());
			}
		}
	}

	game->close();
	return 0;
}

std::string printCurrentVector(Vector2D vec) 
{
	std::string output = "(" + std::to_string(vec.x) + "," + std::to_string(vec.y) + ")\n";
	return output;
}
