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
const std::string FONT_FILENAME = "assets/fonts/Alice-Regular.ttf"; //https://www.1001freefonts.com/alice.font

//SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
//SDL_Surface* gImage = NULL;
//extern SDL_Renderer* gRenderer = NULL;


bool loadMedia();

LTexture t;
const std::string textureFilepath = "assets/images/ball.png";
LTexture background;
const std::string backgroundFilepath = "assets/images/background2.png";
LTexture textTexture;

bool loadMedia() 
{
	bool success = true;

	if (!t.loadFromFile(textureFilepath)) 
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	if (!background.loadFromFile(backgroundFilepath)) 
	{
		printf("Failed to load texture background!\n");
		success = false;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) 
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		success = false;
	}
	else 
	{
		gScreenSurface = SDL_GetWindowSurface(Game::getInstance()->getWindow());
	}
	//initialize ttf
	if (TTF_Init() == -1) 
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	if (!(Game::getInstance()->setFont(FONT_FILENAME, 28))) 
	{
		success = false;
	}
	else 
	{
		SDL_Color textColor = {0, 0, 0};
		if (!textTexture.loadFromRenderedText("Hello SDL", textColor))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}
	}


	return success;
}



int main(int argc, char* args[])
{
	Game::createInstance();
	Game* p_game = Game::getInstance();
	
	if (!p_game->init(SCREEN_WIDTH,SCREEN_HEIGHT))
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
							testVector.print();
							break;
						case SDLK_DOWN:
							printf("DOWN PRESSED ");
							testVector.y = testVector.y - 1;
							testVector.print();
							break;
						case SDLK_RIGHT:
							printf("RIGHT PRESSED ");
							testVector.x = testVector.x + 1;
							testVector.print();
							break;
						case SDLK_LEFT:
							printf("LEFT PRESSED ");
							testVector.x = testVector.x - 1;
							testVector.print();
							break;
						}
					}

				} 
				//Clear Screen
				SDL_SetRenderDrawColor(p_game->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(p_game->getRenderer());

				//Draw Red Quad
				SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
				SDL_SetRenderDrawColor(p_game->getRenderer(), 0xFF, 0x00, 0x00, 0xFF);
				SDL_RenderFillRect(p_game->getRenderer(), &fillRect);

				//Render background
				background.render(0, 0);
				t.render(240, 190);
				textTexture.render((SCREEN_WIDTH - textTexture.getWidth()) / 2, (SCREEN_HEIGHT - textTexture.getHeight()) / 2);
				SDL_RenderPresent(p_game->getRenderer());

				
			}
		}
	}

	textTexture.free();
	t.free();
	background.free();
	p_game->close();
	Game::deleteInstance();
	p_game = nullptr;
	return 0;
}

