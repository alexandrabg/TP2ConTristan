#include "BirdEnemy.h"


BirdEnemy::BirdEnemy() :Enemy()
{
	
}

BirdEnemy::BirdEnemy(Texture& texture)
{
	this->setTexture(texture);
	this->setScale(0.15f, 0.15f);
	this->setPosition(0, 30);
}

void BirdEnemy::Move(float offsetX)
{
	move(offsetX*speed, 0);
	//this->position.x = position.x + SPEED;
}


BirdEnemy::~BirdEnemy()
{
}
