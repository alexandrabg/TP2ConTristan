#include "StandartPlateforme.h"


StandartPlateforme::StandartPlateforme(const Texture& newTexture, const Vector3f coordinates) :
StaticObject()
{
	this->setTexture(newTexture);
	this->setHitbox(IntRect(0, 0, newTexture.getSize().x, newTexture.getSize().y));
	this->setPosition(Vector2f(coordinates.x, coordinates.y));
}

StandartPlateforme::StandartPlateforme(const Texture& newTexture, const Vector3f coordinates, const int offsetX) :
StaticObject()
{
	this->setTexture(newTexture);
	this->setHitbox(IntRect(0, 0, newTexture.getSize().x, newTexture.getSize().y));
	this->setPosition(Vector2f(coordinates.x + offsetX, coordinates.y));
}


StandartPlateforme::~StandartPlateforme()
{
}
