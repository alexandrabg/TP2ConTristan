#include "Hero.h"
#include <math.h>

Hero::Hero(Texture& newTexture, IntRect foot) :
Character(foot), speed(2), isJumping(false), isStillJumping(false), jumpingFrameCounter(999), jumpingSpeed(3), jumpHeight(60), attackSpeed(60)
{
	this->setTexture(newTexture);
	this->setScale(0.2f, 0.2f);
	this->fallingSpeed = 3;
}

Hero::~Hero()
{
}

void Hero::move(const float offsetX, const float offsetY)
{
	Character::move(offsetX * speed, offsetY);
}

void Hero::update()
{
	// Vérifie si le joueur est en chute libre
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

int Hero::getAS() const
{
	return attackSpeed;
}

Vector2f Hero::getPositionHero() const
{
	return positionHero;
}

void Hero::setPositionHero(const Vector2f positionHero)
{
	this->positionHero = positionHero;
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

float Hero::getSpeed() const
{
	return speed;
}

