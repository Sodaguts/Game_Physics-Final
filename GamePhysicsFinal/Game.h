#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
class Game
{
public:

	Game(const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
	~Game();

	bool init(const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
	bool loadMedia();
	void close();


	inline SDL_Renderer* getRenderer() { return gRenderer; };
	inline SDL_Window* getWindow() { return gWindow; };

private:
	SDL_Renderer* gRenderer = NULL;
	SDL_Window* gWindow = NULL;
};

