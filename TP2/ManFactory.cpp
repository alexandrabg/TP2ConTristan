#include "ManFactory.h"


ManFactory::ManFactory()
{
}


ManFactory::~ManFactory()
{
}

FatManEnemy* ManFactory::CreateMan()
{
	return new FatManEnemy(texture.getManTexture());
}
