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
}

void Game::update()
{
}

void Game::render()
{
	this->mainWindow.clear();

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