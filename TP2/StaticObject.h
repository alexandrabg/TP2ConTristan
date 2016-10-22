#pragma once
#include "SpriteMaker.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class StaticObject :
	public Sprite
{
public:
	StaticObject();
	StaticObject(Texture&);
	StaticObject(Texture&,IntRect hitBox);
	~StaticObject();

private:

	IntRect hitbox;

protected:
	void setHitbox(IntRect);

};

