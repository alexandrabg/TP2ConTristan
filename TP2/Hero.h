#pragma once
#include "Character.h"
class Hero :
	public Character
{
public:
	Hero(Texture&);
	~Hero();
	
	void move(float offsetX, float offsetY);
	void update();
	void setIsOnSolidGround(bool);

private:
	float speed;
};

