#include "Particle.h"

Particle::Particle(Vector2D position) 
{
	mPosX = position.x;
	mPosY = position.y;

	mVelX = 0;
	mVelY = 0;
}

Particle::Particle(LTexture* texture) 
{
	//initialize variables
	mPosX = 0;
	mPosY = 0;

	mVelX = 0;
	mVelY = 0;

	mTexture = texture;
	printf("created!");
}

Particle::~Particle() 
{
	delete mTexture;
	mTexture = nullptr;
}

void Particle::attachTexture(LTexture* texture) 
{
	mTexture = texture;
}

void Particle::handleEvent(SDL_Event &e) 
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) 
	{
		//Adjust the velocity
		switch (e.key.keysym.sym) 
		{
			case SDLK_UP: 
				mVelY -= particleVelocity;
				break;
			case SDLK_DOWN:
				mVelY += particleVelocity;
				break;
			case SDLK_LEFT:
				mVelX -= particleVelocity;
				break;
			case SDLK_RIGHT:
				mVelX += particleVelocity;
				break;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0) 
	{
		switch (e.key.keysym.sym) 
		{
			case SDLK_UP:
				mVelY += particleVelocity;
				break;
			case SDLK_DOWN:
				mVelY -= particleVelocity;
				break;
			case SDLK_LEFT:
				mVelX += particleVelocity;
				break;
			case SDLK_RIGHT:
				mVelX -= particleVelocity;
				break;
		}
	}
}

void Particle::move() 
{
	//move the particle left / right
	mPosX += mVelX;
	if ((mPosX < 0) || ((mPosX + PARTICLE_WIDTH) > Game::getInstance()->getScreenWidth())) 
	{
		mPosX -= mVelX;
	}
	mPosY += mVelY;
	if((mPosY < 0) || ((mPosX + PARTICLE_HEIGHT) > Game::getInstance()->getScreenHeight()))
	{
		mPosY -= mVelY;
	}

}

void Particle::render() 
{
	mTexture->render(mPosX, mPosY);
}
