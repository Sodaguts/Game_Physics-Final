#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
class Game
{
public:

	static Game* getInstance();
	static void createInstance();
	static void deleteInstance() { delete game; };
	Game() {};
	//Game(const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
	~Game();

	bool init(const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
	bool loadMedia();
	void close();

	int getNum() { return testNum; };
	void setNum(int num) { testNum = testNum + num; };
	int getData() { return testData; };

	Game(const Game& obj) = delete;

	inline SDL_Renderer* getRenderer() { return gRenderer; };
	inline SDL_Window* getWindow() { return gWindow; };
	inline TTF_Font* getFont() { return gFont; };
	bool setFont(std::string filename, float size);

private:

	static Game* game;

	int testNum = 5;
	int testData = 3;

	SDL_Renderer* gRenderer = NULL;
	SDL_Window* gWindow = NULL;
	TTF_Font* gFont = NULL;
};



