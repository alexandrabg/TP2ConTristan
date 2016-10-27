#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy();
	~Enemy();
	//virtual void Move(float offset);

private:


protected:
	Vector2f position;
};

