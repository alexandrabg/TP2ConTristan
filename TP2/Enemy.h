#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy(Vector2f pos);
	~Enemy();

	void update();

private:


protected:
	Vector2f position;
	int orientation;
};

