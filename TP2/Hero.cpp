#include "Hero.h"

Hero::Hero(Texture& newTexture) :
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
	positionHero.y = startingHeight;
	if (endingHeight - startingHeight <= HAUTEUR_JUMP_MAX)
	{
		positionHero.y++;
		endingHeight++;
	}
	else
		positionHero.y--;
}
