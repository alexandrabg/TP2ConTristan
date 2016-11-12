#pragma once
#include "Enemy.h"
class TextureManager;

class FatManEnemy :
	public Enemy
{
public:
	FatManEnemy(Texture& texture, Vector2f pos);
	~FatManEnemy();
	void Move(float);
private:
	int speed = SPEED / 4;
};

