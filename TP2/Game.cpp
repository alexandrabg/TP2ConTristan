#include "Game.h"

Game::Game()
{
	this->mainWindow.create(VideoMode(LARGEUR, HAUTEUR, 32), "Projet SFML C++");
}

void Game::init()
{
	this->mainWindow.setVerticalSyncEnabled(true);
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
}

void Game::render()
{
	this->mainWindow.clear();
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