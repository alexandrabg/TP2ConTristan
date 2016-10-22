#include "StaticObject.h"

StaticObject::StaticObject():
Sprite()
{
}

StaticObject::StaticObject(Texture& newTexture):
Sprite()
{
	this->setTexture(newTexture);
	hitbox = IntRect(0,0, newTexture.getSize().x, newTexture.getSize().y);
}

StaticObject::StaticObject(Texture& newTexture, IntRect newHitbox):
Sprite(), hitbox(newHitbox)
{
	this->setTexture(newTexture);
}


StaticObject::~StaticObject()
{
}

void StaticObject::setHitbox(IntRect newHitbox)
{
	hitbox = newHitbox;
}
