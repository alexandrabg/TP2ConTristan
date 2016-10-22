#include "StandartPlateforme.h"


StandartPlateforme::StandartPlateforme(Texture& newTexture, Vector2f newPosition) :
StaticObject()
{
	this->setTexture(newTexture);
	this->setHitbox(IntRect(0, 0, newTexture.getSize().x, newTexture.getSize().y));
	this->setPosition(newPosition);
}


StandartPlateforme::~StandartPlateforme()
{
}
