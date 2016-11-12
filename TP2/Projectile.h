#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Projectile: public Sprite
{
public:
	Projectile(const Texture& texture, const int positionX, const int positionY);
	~Projectile();

	int getSpeed();

private:
	int speed;
};

