#pragma once
#include "TextureManager.h"
#include "FatManEnemy.h"

class ManFactory
{
public:
	FatManEnemy* CreateMan();
	~ManFactory();
private:
	ManFactory();
	TextureManager texture;
};

