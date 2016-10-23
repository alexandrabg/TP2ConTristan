#include "Game.h"
#include <iostream>


Game::Game() : frameCounter(0)
{
	this->mainWindow.create(VideoMode(LARGEUR, HAUTEUR, 32), "Projet SFML C++");
	hero = new Hero(textureManager.getHeroSpriteSheet());
}

void Game::init()
{
	mainView = new View(FloatRect(0, 0, LARGEUR, HAUTEUR));
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
		mainView->move(hero->getSpeed(), 0);
		hero->move(1, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		mainView->move(-(hero->getSpeed()), 0);
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
	for (vector<StaticObject*>::iterator it = staticObjects.begin() ; it != staticObjects.end(); it++)
	{
		float pos = hero->getPosition().y + hero->getTextureRect().height * 0.2f;
		if (hero->getPosition().y + hero->getTextureRect().height * 0.2f > (*it)->getPosition().y - 2 && hero->getPosition().y + hero->getTextureRect().height * 0.2f < (*it)->getPosition().y
			&& hero->getPosition().x + hero->getTextureRect().width * 0.2f >(*it)->getPosition().x
			&& hero->getPosition().x < (*it)->getPosition().x + (*it)->getTextureRect().width)
		{
			hero->setIsOnSolidGround(true);
		}
	}
	hero->update();
}

void Game::render()
{
	this->mainWindow.clear();
	mainWindow.setView(*mainView);
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

	delete hero;
	delete mainView;
	for (vector<StaticObject*>::iterator it = staticObjects.begin(); it != staticObjects.end(); it++)
	{
		delete *it;
	}

	return EXIT_SUCCESS;
}