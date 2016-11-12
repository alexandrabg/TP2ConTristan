#pragma once
#include "StaticObject.h"

class SteamSale: public StaticObject
{
public:
	SteamSale(const Texture& texture, const int positionX, const int positionY);
	~SteamSale();
};

