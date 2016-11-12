#include "SnailEnemy.h"


SnailEnemy::SnailEnemy(Texture& texture, Vector2f pos) : Enemy(pos)
{
	this->setTexture(texture);
	this->setScale(0.03f, 0.03f);
}

void SnailEnemy::Move(float offsetX)
{
	move(offsetX*-speed, 0);
}

SnailEnemy::~SnailEnemy()
{
}
