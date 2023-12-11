#include "Particle.h"

Particle::Particle(Vector2D position) 
{
	mPosX = position.x;
	mPosY = position.y;

	mVelX = 0.03;
	mVelY = 0.03;
}

Particle::Particle(LTexture* texture) 
{
	//initialize variables
	mPosX = 0;
	mPosY = 0;

	mVelX = 0.03;
	mVelY = 0.03;

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
	
}

void Particle::move(float dt, SDL_Rect& wall) 
{
	//initial velocity
	mPosX += mVelX * dt;

	if ((mPosX < 0) || (mPosX + radius > Game::getInstance()->SCREEN_W) || checkCollision(radius, wall)) 
	{
		mPosX -= mVelX;
	}

	mPosY += mVelY * dt;

	if ((mPosY < 0) || (mPosX + radius > Game::getInstance()->SCREEN_H) || checkCollision(radius, wall)) 
	{
		mPosY -= mVelY;
	}

}

void Particle::move(float dt) 
{
	mPosX += mVelX * dt;
	mPosY += mVelY * dt;
}

bool Particle::checkCollision(float radius, SDL_Rect wall) 
{
	//sides of the rect
	int left, right, top, bottom;
	left = wall.x;
	right = wall.x + wall.w;
	top = wall.y;
	bottom = wall.y + wall.h;

	//current position of Particle+radius
	Vector2D center = Vector2D(mPosX - 16, mPosY - 16);
	Vector2D radiusPos = Vector2D(radius + center.x, radius + center.y);


}

void Particle::render() 
{
	mTexture->render(mPosX, mPosY);
}
