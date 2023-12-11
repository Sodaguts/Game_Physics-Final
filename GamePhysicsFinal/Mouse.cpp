#include "Mouse.h"

Mouse::Mouse() 
{
	mPosition.x = 0;
	mPosition.y = 0;
}

void Mouse::setPosition(Vector2D pos) 
{
	mPosition.x = pos.x;
	mPosition.y = pos.y;
}

void Mouse::setPosition(float x, float y) 
{
	mPosition.x = x;
	mPosition.y = y;
}

void Mouse::handleEvent(SDL_Event* e) 
{
	if (e->type == SDL_MOUSEBUTTONDOWN) 
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);
		Vector2D position = Vector2D(x,y);
		position.print();
		Game::getInstance()->createParticle(position);
	}
}