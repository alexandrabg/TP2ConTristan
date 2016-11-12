#include "SnailFactory.h"


SnailFactory::SnailFactory()
{
}


SnailFactory::~SnailFactory()
{
}

SnailEnemy* SnailFactory::CreateSnail()
{
	return new SnailEnemy(texture->getSnailTexture(), Vector2f(0,0));
}
