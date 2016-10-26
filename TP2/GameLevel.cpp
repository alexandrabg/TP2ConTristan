#include "GameLevel.h"


GameLevel::GameLevel()
{
	pStaticObjects = &staticObjects;
	mainView = new View(FloatRect(0, 0, LARGEUR, HAUTEUR));
	staticObjects.push_back(new StaticObject(textureManager.getBgTexture(), IntRect(0,0,0,0), false));
	staticObjects.push_back(new StandartPlateforme(textureManager.getPlateformeSS(), Vector2f(50, 400)));
}


GameLevel::~GameLevel()
{
	delete mainView;
	for (vector<StaticObject*>::iterator it = staticObjects.begin(); it != staticObjects.end(); ++it)
	{
		delete *it;
	}
}

View* GameLevel::getMainView()
{
	return mainView;
}

vector<StaticObject*>* GameLevel::getStaticObjects()
{
	return pStaticObjects;
}
