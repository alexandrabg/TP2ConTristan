#include "FatManEnemy.h"
#include "Constantes.h"


FatManEnemy::FatManEnemy(Texture& texture, Vector2f pos) : Enemy(pos)
{
	this->setTexture(texture);
	this->setScale(0.3f, 0.3f);
}


FatManEnemy::~FatManEnemy()
{
}

void FatManEnemy::Move(float offsetX)
{
	move(offsetX* speed, 0);
}
