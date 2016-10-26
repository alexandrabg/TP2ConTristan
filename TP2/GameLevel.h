#pragma once
#include "SpriteMaker.h"
#include <SFML/Graphics.hpp>
#include "Constantes.h"
#include "StaticObject.h"
#include "TextureManager.h"
#include "StandartPlateforme.h"

using namespace sf;
class GameLevel
{
public:
	GameLevel();
	~GameLevel();

	View* getMainView();
	vector<StaticObject*>* getStaticObjects();

private:
	vector<StaticObject*> staticObjects;
	vector<StaticObject*>* pStaticObjects;
	TextureManager textureManager;

	View* mainView;
};

