#pragma once
#include "Vector2D.h"
#include <SDL.h>
#include "Game.h"
#include "LTexture.h"
class Particle
{
	public:
		//functions and stuff
		Particle(LTexture* texture);
		~Particle();

		void handleEvent(SDL_Event& e);

		void move();

		void render();

		int getVelocity() { return particleVelocity; };
		Vector2D getDimensions() { return Vector2D(PARTICLE_WIDTH, PARTICLE_HEIGHT); };
		
	private:
		int mPosX, mPosY;
		int mVelX, mVelY;

		int particleVelocity = 10;
		static const int PARTICLE_WIDTH = 32;
		static const int PARTICLE_HEIGHT = 32;

		LTexture* mTexture = NULL;
};

