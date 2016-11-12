#include "Game.h"
#include <iostream>


Game::Game() : frameCounter(0)
{
	this->mainWindow.create(VideoMode(LARGEUR, HAUTEUR, 32), "Projet SFML C++");
	hero = gameLevel.gameLevelInit();
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

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (hero->getPosition().x > LARGEUR / 5
			&& hero->getPosition().x < 2400)
		{
			gameLevel.getMainView()->move((hero->getSpeed()), 0);
			(*(*gameLevel.getStaticObjects()).begin())->move(hero->getSpeed()/2, 0);
		}
		hero->move(1, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (hero->getPosition().x > LARGEUR / 5
			&& hero->getPosition().x < 2400)
		{
			gameLevel.getMainView()->move(-(hero->getSpeed()), 0);
			(*(*gameLevel.getStaticObjects()).begin())->move(-hero->getSpeed()/2, 0);
		}
		hero->move(-1, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		hero->Jump();
	}
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		gameLevel.throwCheetos(hero);
	}
}

void Game::update()
{
	hero->setIsOnSolidGround(false);
	if (gameLevel.checkPlatformCollision(hero))
		hero->setIsOnSolidGround(true);
	hero->update();
	gameLevel.update();
}

void Game::render()
{
	this->mainWindow.clear();
	mainWindow.setView(*gameLevel.getMainView());
	for (vector<StaticObject*>::iterator it = (*gameLevel.getStaticObjects()).begin(); it != (*gameLevel.getStaticObjects()).end(); ++it)
	{
		mainWindow.draw(**it);
	}

	gameLevel.draw(mainWindow);

	mainWindow.draw(*hero);
	this->mainWindow.display();

}

int Game::run()
{
	this->init();

	while (this->mainWindow.isOpen())
	{
		frameCounter++;
		this->processInputs();
		this->update();
		this->render();		
	}
	return EXIT_SUCCESS;
}