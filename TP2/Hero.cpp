#include "Hero.h"
#include <math.h>

Hero::Hero(Texture& newTexture, IntRect foot) :
Character(), speed(2), isJumping(false), isStillJumping(false), jumpingFrameCounter(999), jumpingSpeed(3), fallingSpeed(3), jumpHeight(25), footSurface(foot)
{
	this->setTexture(newTexture);
	this->setScale(0.2f, 0.2f);
}

Hero::~Hero()
{
}

void Hero::move(float offsetX, float offsetY)
{
	Character::move(offsetX * speed, offsetY);
}

void Hero::update()
{
	if (!isOnSolidGround && ( !isJumping || jumpingFrameCounter > jumpHeight) )
	{
		Character::move(0, fallingSpeed);
	}
	if (isJumping && isStillJumping)
	{
		if (jumpingFrameCounter < jumpHeight)
		{
			this->move(0, -jumpingSpeed);
		}
		else
			isStillJumping = false;
		jumpingFrameCounter++;
		isJumping = false;
	}
	else if (!isJumping && isStillJumping)
	{
		isStillJumping = false;
		jumpingFrameCounter = 999;
	}
}

Vector2f Hero::getPositionHero() const
{
	return positionHero;
}

void Hero::setPositionHero(Vector2f positionHero)
{
	this->positionHero = positionHero;
}



void Hero::setIsOnSolidGround(bool isIt)
{
	isOnSolidGround = isIt;
}

void Hero::Jump()
{

	if (isOnSolidGround)
	{
		jumpingFrameCounter = 1;
		isStillJumping = true;
	}
	isJumping = true;
}

float Hero::getSpeed()
{
	return speed;
}

IntRect Hero::getFootSurface()
{
	return footSurface;
}
