#include "Projectile.h"


Projectile::Projectile(Texture texture, int positionX, int positionY)
{
	this->setTexture(texture);
	this->setPosition(positionX, positionY);
	//this->setScale();
}


Projectile::~Projectile()
{
}
