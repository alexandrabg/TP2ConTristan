#pragma once
#include "Enemy.h"
class SnailEnemy :
	public Enemy
{
public:
	SnailEnemy();
	SnailEnemy(Texture&);
	~SnailEnemy();
	void Move(float);
private:
	int life = 10;
	int speed = SPEED / 10;
};

