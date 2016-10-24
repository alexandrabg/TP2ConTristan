#include "Game.h"
#include <iostream>


Game::Game() : frameCounter(0)
{
	this->mainWindow.create(VideoMode(LARGEUR, HAUTEUR, 32), "Projet SFML C++");
	hero = new Hero(textureManager.getHeroSpriteSheet());
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
		gameLevel.getMainView()->move(hero->getSpeed(), 0);
		hero->move(1, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		gameLevel.getMainView()->move(-(hero->getSpeed()), 0);
		hero->move(-1, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		hero->Jump();
	}
}

void Game::update()
{

	hero->setIsOnSolidGround(false);
	for (vector<StaticObject*>::iterator it = (*gameLevel.getStaticObjects()).begin(); it != (*gameLevel.getStaticObjects()).end(); ++it)
	{
		if (hero->getPosition().y + hero->getTextureRect().height * 0.2f > (*it)->getPosition().y - 3 && hero->getPosition().y + hero->getTextureRect().height * 0.2f < (*it)->getPosition().y
			&& hero->getPosition().x + hero->getTextureRect().width * 0.2f >(*it)->getPosition().x
			&& hero->getPosition().x < (*it)->getPosition().x + (*it)->getTextureRect().width
			&& (*it)->getIsSolid())
		{
			hero->setIsOnSolidGround(true);
		//	hero->setPosition(hero->getPosition().x, (*it)->getPosition().y - hero->getTextureRect().height);
		}
	}
	hero->update();
}

void Game::render()
{
	this->mainWindow.clear();
	mainWindow.setView(*gameLevel.getMainView());
	mainWindow.draw(*hero);
	for (vector<StaticObject*>::iterator it = (*gameLevel.getStaticObjects()).begin(); it != (*gameLevel.getStaticObjects()).end(); ++it)
	{
		mainWindow.draw(**it);
	}

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

	delete hero;
	for (vector<StaticObject*>::iterator it = (*gameLevel.getStaticObjects()).begin(); it != (*gameLevel.getStaticObjects()).end(); it++)
	{
		delete *it;
	}

	return EXIT_SUCCESS;
}