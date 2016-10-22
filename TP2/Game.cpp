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
	tBG.loadFromFile("Assets\\TikiRossBG.png");
	BG.setTexture(tBG);
	BG.setPosition(0, 0);
	BG.setOrigin(0, 0);
	staticObjects.push_back(new StandartPlateforme(textureManager.getPlateformeSS(), Vector2f(50, 400)));
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
		hero->move(1, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		hero->move(-1, 0);
	}
}

void Game::update()
{
	hero->update();

	BG.setPosition(BG.getPosition() + Vector2f(-0.5, 0));
	if (BG.getPosition().x - LARGEUR < -2000)
		BG.setPosition(0, 0);

	hero->setIsOnSolidGround(false);
	for (vector<StaticObject*>::iterator it = staticObjects.begin() ; it != staticObjects.end(); it++)
	{
		if (hero->getPosition().y + hero->getTextureRect().height * 0.2f - 13 == (*it)->getPosition().y
			&& hero->getPosition().x + hero->getTextureRect().width * 0.2f > (*it)->getPosition().x
			&& hero->getPosition().x < (*it)->getPosition().x + (*it)->getTextureRect().width)
		{
			hero->setIsOnSolidGround(true);
		}
	}
}

void Game::render()
{
	this->mainWindow.clear();
	mainWindow.draw(BG);
	mainWindow.draw(*hero);
	mainWindow.draw(*staticObjects[0]);

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