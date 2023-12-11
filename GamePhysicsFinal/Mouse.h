#pragma once
#include <SDL.h>
#include "Vector2D.h"

class Mouse
{
	public:
		Mouse();

		void setPosition(Vector2D position);
		void setPosition(float x, float y);
		void handleEvent(SDL_Event* e);

		Vector2D getPosition() { return mStoredPosition; };
	private:
		SDL_Point mPosition;
		Vector2D mStoredPosition;
};

