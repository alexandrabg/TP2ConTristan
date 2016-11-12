#include "BirdEnemy.h"



BirdEnemy::BirdEnemy(Texture& texture, Vector2f pos) : Enemy(pos)
{
	this->setTexture(texture);
	this->setScale(0.15f, 0.15f);
}

void BirdEnemy::Move(float offsetX)
{
	move(offsetX*speed, 0);
	//this->position.x = position.x + SPEED;
}


BirdEnemy::~BirdEnemy()
{
}
