#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class StaticObject :
	public Sprite
{
public:
	StaticObject();
	StaticObject(Texture&);
	StaticObject(Texture&, IntRect hitBox);
	StaticObject(Texture&, IntRect hitBox, bool solid);
	~StaticObject();

	bool getIsSolid();

private:

	IntRect hitbox;
	bool isSolid;

protected:
	void setHitbox(IntRect);
	void setIsSolid(bool);

};

