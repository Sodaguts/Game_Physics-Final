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
		extern SDL_Renderer* gRenderer;
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
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
	return false;
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
