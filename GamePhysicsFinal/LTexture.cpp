#include "LTexture.h"


LTexture::LTexture() 
{
	//initializes variables
	mTexture = NULL;
	mHeight = 0;
	mWidth = 0;	
}

LTexture::~LTexture() 
{
	//deallocates memory
	free();
}

int LTexture::returnTestNum() 
{
	return Game::getInstance()->getNum();
}

int LTexture::returnData() 
{
	return Game::getInstance()->getData();
}

bool LTexture::loadFromFile(std::string path) 
{
	free();
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) 
	{
		printf("Unable to load image %s! SDL_image Error: %s\n",path.c_str(), IMG_GetError());
	}
	else 
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		//create texture from surface pixels
		//TODO: CHANGE
		//SDL_Renderer* gRenderer;
		SDL_Renderer* gRend = Game::getInstance()->getRenderer();
		//newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		newTexture = SDL_CreateTextureFromSurface(gRend, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	mTexture = newTexture;
	return mTexture != NULL;
	
}

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
	//Get rid of preexisting texture
	free();

	//SDL_Surface* textSurface = TTF_RenderText_Solid();
	SDL_Surface* textSurface = TTF_RenderText_Solid(Game::getInstance()->getFont(), textureText.c_str(), textColor);
	if (textSurface == NULL) 
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else 
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(Game::getInstance()->getRenderer(), textSurface);
		if (mTexture == NULL) 
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else 
		{
			//get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		SDL_FreeSurface(textSurface);
	}
	return mTexture != NULL;
}

void LTexture::free() 
{
	if (mTexture != NULL) 
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(int x, int y) 
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = {x, y, mWidth, mHeight};
	//SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
	SDL_RenderCopy(Game::getInstance()->getRenderer(), mTexture, NULL, &renderQuad);
}
