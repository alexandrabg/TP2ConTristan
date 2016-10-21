#include "Game.h"

Game::Game()
{
	this->mainWindow.create(VideoMode(LARGEUR, HAUTEUR, 32), "Projet SFML C++");
}

void Game::init()
{
	this->mainWindow.setVerticalSyncEnabled(true);
	tBG.loadFromFile("Assets\\TikiRossBG.png");
	BG.setTexture(tBG);
	BG.setPosition(0, 0);
	BG.setOrigin(0, 0);
}

void Game::processInputs()
{
	Event event;

	while (this->mainWindow.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			this->mainWindow.close();
		}
	}
	hero.Move();
}

void Game::update()
{
	hero.GetPositionHero();
	BG.setPosition(BG.getPosition() + Vector2f(-0.5, 0));
	if (BG.getPosition().x - LARGEUR < -2000)
		BG.setPosition(0, 0);
}

void Game::render()
{
	this->mainWindow.clear();
	mainWindow.draw(BG);
	mainWindow.draw(hero.GetSprite());

	this->mainWindow.display();

}

int Game::run()
{
	this->init();

	while (this->mainWindow.isOpen())
	{
		this->processInputs();
		this->update();
		this->render();		
	}

	return EXIT_SUCCESS;
}