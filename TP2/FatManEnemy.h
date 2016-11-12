#pragma once
#include "Enemy.h"
class TextureManager;

class FatManEnemy :
	public Enemy
{
public:
	FatManEnemy(const Texture& texture, const Vector2f pos);
	~FatManEnemy();
	void Move(const float);
private:
	int speed = SPEED / 4;
};

