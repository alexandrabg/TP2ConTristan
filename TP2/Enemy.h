#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy();
	~Enemy();

private:


protected:
	Vector2f position;
};

