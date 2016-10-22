#include "Hero.h"

Hero::Hero(Texture& newTexture):
	Character(), speed(2)
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
	if (!isOnSolidGround)
	{
		Character::move(0, 1);
	}
}

void Hero::setIsOnSolidGround(bool isIt)
{
	isOnSolidGround = isIt;
}
