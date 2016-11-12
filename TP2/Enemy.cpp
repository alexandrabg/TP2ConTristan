#include "Enemy.h"


Enemy::Enemy(Vector2f pos) : orientation(1)
{
	this->setPosition(pos.x, pos.y);
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
	if (!isOnSolidGround)
		orientation *= -1;
	Character::move(1 * orientation, 0);
	if (!isOnSolidGround)
	{
		Character::move(0, fallingSpeed);
	}
}