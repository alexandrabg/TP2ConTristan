#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Projectile: public Sprite
{
public:
	Projectile(Texture texture, int positionX, int positionY);
	~Projectile();
};

