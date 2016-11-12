#include "StaticObject.h"

StaticObject::StaticObject():
Sprite(), isSolid(true)
{
}

StaticObject::StaticObject(const Texture& newTexture) :
Sprite(), isSolid(true)
{
	this->setTexture(newTexture);
	hitbox = IntRect(0,0, newTexture.getSize().x, newTexture.getSize().y);
}

StaticObject::StaticObject(const Texture& newTexture, const IntRect newHitbox) :
Sprite(), hitbox(newHitbox), isSolid(true)
{
	this->setTexture(newTexture);
}

StaticObject::StaticObject(const Texture& newTexture, const IntRect newHitbox, const bool isSolid1) :
Sprite(), hitbox(newHitbox)
{
	this->setTexture(newTexture);
	this->isSolid = isSolid1;
}


StaticObject::~StaticObject()
{
}

void StaticObject::setHitbox(IntRect newHitbox)
{
	hitbox = newHitbox;
}

bool StaticObject::getIsSolid()
{
	return isSolid;
}