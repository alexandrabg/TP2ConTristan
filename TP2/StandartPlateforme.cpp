#include "StandartPlateforme.h"


StandartPlateforme::StandartPlateforme(Texture& newTexture, Vector3f coordinates) :
StaticObject()
{
	this->setTexture(newTexture);
	this->setHitbox(IntRect(0, 0, newTexture.getSize().x, newTexture.getSize().y));
	this->setPosition(Vector2f(coordinates.x, coordinates.y));
	//this->length = coordinates.z;
}


StandartPlateforme::~StandartPlateforme()
{
}
