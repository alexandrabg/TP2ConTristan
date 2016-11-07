#include "EnemyFactory.h"

EnemyFactory::EnemyFactory()
{

}


EnemyFactory::~EnemyFactory()
{

}

Enemy* EnemyFactory::CreateEnemyType(EnemyType type)
{
	switch (type)
	{
	case Bird:
		return new BirdEnemy(texture.getBirdTexture());
	case Snail:
		return new SnailEnemy(texture.getSnailTexture());
	case Man:
		return new FatManEnemy(texture.getManTexture());
	}
}

