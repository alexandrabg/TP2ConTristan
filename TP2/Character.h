#pragma once
#include <SFML/Graphics.hpp>
#include "Constantes.h"

using namespace sf;

class Character : 
		public Sprite
{
public:
	Character();
	Character(IntRect);
	~Character();

	void setIsOnSolidGround(bool);
	IntRect& getFootSurface();

private:
protected:
	bool isOnSolidGround;
	float fallingSpeed;
	IntRect footSurface;

};

