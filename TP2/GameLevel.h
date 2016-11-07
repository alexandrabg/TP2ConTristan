#pragma once
#include <SFML/Graphics.hpp>
#include "Constantes.h"
#include "StaticObject.h"
#include "TextureManager.h"
#include "StandartPlateforme.h"
#include "Plateform.h"
#include "Hero.h"
#include "MoutainDew.h"

using namespace sf;
class GameLevel
{
public:
	GameLevel();
	~GameLevel();

	View* getMainView();
	vector<StaticObject*>* getStaticObjects();
	void draw(RenderWindow& mainWindow);
	bool checkPlatformCollision(Hero* hero);

private:
	void OpenLevelFile();
	vector<vector<StaticObject*>*> sizeablePlatforms;
	vector<StaticObject*> staticObjects;
	vector<StaticObject*>* pStaticObjects;
	TextureManager textureManager;
	vector<StaticObject*>* vMtnDew;
	vector<StaticObject*>* vSale;
	View* mainView;
};

