#include "FatManEnemy.h"
#include "Constantes.h"


FatManEnemy::FatManEnemy(Texture& texture)
{
	this->setTexture(texture);
	this->setScale(0.3f, 0.3f);
	this->setPosition(30, 80);
}


FatManEnemy::~FatManEnemy()
{
}

void FatManEnemy::Move(float offsetX)
{
	move(offsetX* speed, 0);
}
