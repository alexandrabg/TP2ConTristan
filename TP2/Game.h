#pragma once

#include <SFML/Graphics.hpp>
#include "Character.h"

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
	Character hero;
	Sprite BG;
	//Sprite heroSprite;
	//Texture heroTexture;
	static const int LARGEUR = 640;
	static const int HAUTEUR = 480;
};