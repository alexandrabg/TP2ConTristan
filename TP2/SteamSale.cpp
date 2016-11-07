#include "SteamSale.h"


SteamSale::SteamSale(Texture& texture, int positionX, int positionY)
{
	this->setTexture(texture);
	this->setPosition(positionX, positionY);
	this->setScale(0.5f, 0.5f);
}


SteamSale::~SteamSale()
{
}
