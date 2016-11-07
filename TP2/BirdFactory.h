#pragma once
#include"TextureManager.h"
#include "BirdEnemy.h"

class BirdFactory
{
public:
	BirdEnemy* CreateBird();
	~BirdFactory();
private:
	BirdFactory();
	TextureManager texture;
};

