#pragma once
#include <SFML/Graphics.hpp>
#include "Constantes.h"

using namespace sf;

class Character : 
		public Sprite
{
public:
	Character();
	~Character();

private:
protected:
	bool isOnSolidGround;

};

