#pragma once

#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "TextureManager.h"
#include "StaticObject.h"
#include "StandartPlateforme.h"
#include "GameLevel.h"
#include "BirdEnemy.h"
#include "SnailEnemy.h"

using namespace sf;

class Game
{
public:
	Game();
	int run();

	static const int LARGEUR = 640;
	static const int HAUTEUR = 480;

private:
	RenderWindow mainWindow;

	void init();
	void processInputs();
	void update();
	void render();
	BirdEnemy* bird;
	SnailEnemy* snail;
	GameLevel gameLevel;
	TextureManager textureManager;

	int frameCounter;
	Hero* hero;
};