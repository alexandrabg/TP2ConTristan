#include "Projectile.h"

Projectile::Projectile(const Texture& texture, const int positionX, const int positionY) : speed(2)
{
	this->setTexture(texture);
	this->setPosition(positionX, positionY);
	this->setScale(0.1, 0.1);
}


Projectile::~Projectile()
{
}

int Projectile::getSpeed()
{
	return speed;
}