#pragma once
#include "Enemy.h"
#include "TextureManager.h"
#include "BirdEnemy.h"
#include "SnailEnemy.h"
#include "FatManEnemy.h"

enum EnemyType;

class EnemyFactory
{
public:
	enum EnemyType{Bird, Snail, Man};
	~EnemyFactory();
	Enemy* CreateEnemyType(EnemyType type);
private:
	TextureManager texture;
	EnemyFactory();
};

