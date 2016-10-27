#include "SnailEnemy.h"


SnailEnemy::SnailEnemy()
{
}

SnailEnemy::SnailEnemy(Texture& texture)
{
	this->setTexture(texture);
	this->setScale(0.03f, 0.03f);
	this->setPosition(480, 30);
}

void SnailEnemy::Move(float offsetX)
{
	move(offsetX*-speed, 0);
}

SnailEnemy::~SnailEnemy()
{
}
