#pragma once
#include "StaticObject.h"

class SteamSale: public StaticObject
{
public:
	SteamSale(Texture& texture, int positionX, int positionY);
	~SteamSale();
};

