#include "Character.h"
#include <iostream>


Character::Character() :
Sprite(), isOnSolidGround(false), fallingSpeed(1)
{
	footSurface = this->getTextureRect();
}

Character::Character(IntRect foot) :
Sprite(), isOnSolidGround(false), fallingSpeed(3), footSurface(foot)
{
}

Character::~Character()
{
}

void Character::setIsOnSolidGround(bool isItOnSolidGround)
{
	isOnSolidGround = isItOnSolidGround;
}

IntRect& Character::getFootSurface()
{
	return footSurface;
}