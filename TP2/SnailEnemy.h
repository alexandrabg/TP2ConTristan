#pragma once
#include "Enemy.h"
class SnailEnemy :
	public Enemy
{
public:
	SnailEnemy(Texture&, Vector2f pos);
	~SnailEnemy();
	void Move(float);
private:
	int life = 10;
	int speed = SPEED / 100;
};

