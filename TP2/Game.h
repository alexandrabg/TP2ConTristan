#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

class Game
{
private:
	RenderWindow mainWindow;

	void init();
	void processInputs();
	void update();
	void render();

public:
	Game();
	int run();

	const int LARGEUR = 640;
	const int HAUTEUR = 480;
};