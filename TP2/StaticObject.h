#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class StaticObject :
	public Sprite
{
public:
	StaticObject();
	StaticObject(const Texture&);
	StaticObject(const Texture&, const IntRect hitBox);
	StaticObject(const Texture&, const IntRect hitBox, const bool solid);
	~StaticObject();

	bool getIsSolid();

private:

	IntRect hitbox;
	bool isSolid;

protected:
	void setHitbox(IntRect);
	void setIsSolid(bool);

};

