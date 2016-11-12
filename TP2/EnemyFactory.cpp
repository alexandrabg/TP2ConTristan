#include "EnemyFactory.h"

EnemyFactory::EnemyFactory()
{

}


EnemyFactory::~EnemyFactory()
{

}

Enemy* EnemyFactory::CreateEnemyType(int type, Vector2f pos)
{
	switch (type)
	{
	case 0:
		return new BirdEnemy(texture.getBirdTexture(), Vector2f(pos.x,pos.y - 100));
	case 1:
		return new SnailEnemy(texture.getSnailTexture(), Vector2f(pos.x, pos.y - 40));
	case 2:
		return new FatManEnemy(texture.getManTexture(), Vector2f(pos.x, pos.y - 150));
	}
}

