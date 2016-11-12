#pragma once
#include "Enemy.h"
#include "Constantes.h"
class BirdEnemy :
	public Enemy
{
public:
	BirdEnemy(Texture&, Vector2f pos);
	~BirdEnemy();
	virtual void Move(float);
private:
	int life = 10;
	int speed = SPEED / 3;
};

