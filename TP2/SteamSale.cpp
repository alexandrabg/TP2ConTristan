#include "SteamSale.h"


SteamSale::SteamSale(const Texture& texture, const int positionX, const int positionY)
{
	this->setTexture(texture);
	this->setPosition(positionX, positionY);
	this->setScale(0.5f, 0.5f);
}


SteamSale::~SteamSale()
{
}
