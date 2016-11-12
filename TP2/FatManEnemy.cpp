#include "FatManEnemy.h"
#include "Constantes.h"


FatManEnemy::FatManEnemy(const Texture& texture, const Vector2f pos) : Enemy(pos)
{
	this->setTexture(texture);
	this->setScale(0.3f, 0.3f);
}


FatManEnemy::~FatManEnemy()
{
}

void FatManEnemy::Move(const float offsetX)
{
	move(offsetX* speed, 0);
}
