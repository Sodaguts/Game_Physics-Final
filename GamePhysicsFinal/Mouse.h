#pragma once
#include <SDL.h>
#include "Vector2D.h"
class Mouse
{
	public:
		Mouse();

		void setPosition(Vector2D position);
		void handleEvent(SDL_Event* e);
	private:
		SDL_Point mPosition;
};

