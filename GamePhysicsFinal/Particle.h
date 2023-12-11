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

		void move(float dt, SDL_Rect& wall);
		void move(float dt);

		void render();
		void attachTexture(LTexture* texture);

		int getVelocity() { return particleVelocity; };
		Vector2D getDimensions() { return Vector2D(PARTICLE_WIDTH, PARTICLE_HEIGHT); };
		

	private:
		float mPosX, mPosY;
		float mVelX, mVelY;

		int particleVelocity = 10;
		float radius = 16;

		LTexture* mTexture = NULL;
		static const int PARTICLE_WIDTH = 32;
		static const int PARTICLE_HEIGHT = 32;

		//void shiftColliders();
		bool checkCollision(float radius, SDL_Rect wwall );
};

