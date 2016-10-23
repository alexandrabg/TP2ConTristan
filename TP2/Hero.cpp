#include "Hero.h"
#include <math.h>

Hero::Hero(Texture& newTexture) :
Character(), speed(2), isJumping(false), jumpingFrameCounter(999)
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
	if (!isOnSolidGround && ( !isJumping || jumpingFrameCounter > 60) )
	{
		Character::move(0, 2);
	}
	if (isJumping)
	{
		if (jumpingFrameCounter < 60)
		{
			this->move(0, -2);
		}
		jumpingFrameCounter++;
		isJumping = false;
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
	}
	isJumping = true;
}

float Hero::getSpeed()
{
	return speed;
}
