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
	EnemyFactory();
	~EnemyFactory();
	Enemy* CreateEnemyType(int type, Vector2f pos);
private:
	TextureManager texture;
};

