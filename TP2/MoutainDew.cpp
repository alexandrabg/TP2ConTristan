#include "MoutainDew.h"


MoutainDew::MoutainDew(Texture& texture, int positionX, int positionY): StaticObject()
{
	this->setTexture(texture);
	this->setPosition(positionX, positionY);
	this->setScale(0.2f, 0.2f);
}


MoutainDew::~MoutainDew()
{
}
