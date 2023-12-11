#pragma once
#include "Vector2D.h"
#include <SDL.h>
#include "LTexture.h"


class Particle
{
	public:
		//functions and stuff
		Particle(Vector2D position);
		Particle(LTexture* texture);
		~Particle();

		void handleEvent(SDL_Event& e);

		void move();

		void render();
		void attachTexture(LTexture* texture);

		int getVelocity() { return particleVelocity; };
		Vector2D getDimensions() { return Vector2D(PARTICLE_WIDTH, PARTICLE_HEIGHT); };
		
	private:
		int mPosX, mPosY;
		int mVelX, mVelY;

		int particleVelocity = 10;
		int radius = 16;

		LTexture* mTexture = NULL;
		static const int PARTICLE_WIDTH = 32;
		static const int PARTICLE_HEIGHT = 32;
};

