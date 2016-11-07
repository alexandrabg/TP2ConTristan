#include "BirdFactory.h"


BirdFactory::BirdFactory()
{
}


BirdFactory::~BirdFactory()
{
}

BirdEnemy* BirdFactory::CreateBird()
{
	return new BirdEnemy(texture.getBirdTexture());
}

