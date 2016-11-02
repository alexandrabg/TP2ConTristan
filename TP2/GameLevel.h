#pragma once
#include <SFML/Graphics.hpp>
#include "Constantes.h"
#include "StaticObject.h"
#include "TextureManager.h"
#include "StandartPlateforme.h"
#include "Plateform.h"

using namespace sf;
class GameLevel
{
public:
	GameLevel();
	~GameLevel();

	View* getMainView();
	vector<StaticObject*>* getStaticObjects();

private:
	void OpenLevelFile();
	vector<StaticObject*> staticObjects;
	vector<StaticObject*>* pStaticObjects;
	TextureManager textureManager;

	View* mainView;
};

