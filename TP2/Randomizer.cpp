#include "Randomizer.h"


Randomizer::Randomizer()
{
}


Randomizer::~Randomizer()
{
}

Randomizer* Randomizer::GetInstance()
{
	if (instance == nullptr)
		instance = new Randomizer();
	return instance;
}

