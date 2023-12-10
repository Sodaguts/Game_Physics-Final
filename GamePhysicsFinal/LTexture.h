#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>
class LTexture
{
	public:
		LTexture();
		~LTexture();

		bool loadFromFile(std::string path);

		bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

		void free();

		void setColor(Uint8 red, Uint8 green, Uint8 blue);

		void setBlendMode(SDL_BlendMode blending);

		void setAlpha(Uint8 alpha);

		void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void render(int x, int y);

		int getWidth() { return mWidth; };
		int getHeight() { return mHeight; };
	private:
		SDL_Texture* mTexture;

		int mWidth;
		int mHeight;
};

