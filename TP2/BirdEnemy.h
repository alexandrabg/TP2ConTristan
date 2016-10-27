#pragma once
#include "Enemy.h"
#include "Constantes.h"
class BirdEnemy :
	public Enemy
{
public:
	BirdEnemy();
	BirdEnemy(Texture&);
	~BirdEnemy();
	virtual void Move(float);
private:
	int life = 10;
	int speed = SPEED / 3;
};

