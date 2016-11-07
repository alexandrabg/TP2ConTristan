#pragma once
#include "TextureManager.h"
#include "SnailEnemy.h"

class SnailFactory
{
public:
	SnailEnemy* CreateSnail();
	~SnailFactory();
private:
	SnailFactory();
	TextureManager* texture;
};

