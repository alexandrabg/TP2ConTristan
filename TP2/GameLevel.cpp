#include "GameLevel.h"


GameLevel::GameLevel()
{
	pStaticObjects = &staticObjects;
	mainView = new View(FloatRect(0, 0, LARGEUR, HAUTEUR));
	staticObjects.push_back(new StaticObject(textureManager.getBgTexture(), IntRect(0,0,0,0), false));
	OpenLevelFile();
}


GameLevel::~GameLevel()
{
	delete mainView;
	for (vector<StaticObject*>::iterator it = staticObjects.begin(); it != staticObjects.end(); ++it)
	{
		delete *it;
	}
	for (vector<vector<StaticObject*>*>::iterator it = sizeablePlatforms.begin(); it != sizeablePlatforms.end(); ++it)
	{
		for (vector<StaticObject*>::iterator it2 = (**it).begin(); it2 != (**it).end(); ++it2)
		{
			delete *it2;
		}
		delete *it;
	}
}

void GameLevel::OpenLevelFile()
{
	ifstream filename;
	filename.open("Assets\\Platforms.txt");
	if (!filename)
	{
		cout << "Cannot open file" << endl;
	}

	if (filename)
	{
		string coordinate = "";
		while (filename >> coordinate)
		{
			for (size_t i = 0; i < strlen(coordinate.c_str()); i++)
			{
				if (coordinate[i] == ',')
					coordinate[i] = ' ';
			}
			stringstream ss(coordinate);

			Vector3f coordinates;
			ss >> coordinates.x;
			ss >> coordinates.y;
			ss >> coordinates.z;
			coordinates.y = 470 - coordinates.y;


			vector<StaticObject*>* vPlat = new vector<StaticObject*>();

			vPlat->push_back(new StandartPlateforme(textureManager.getLeftPlatTexture(), coordinates));
			coordinates.z -= 15;
			vPlat->push_back(new StandartPlateforme(textureManager.getRightPlatTexture(), coordinates, coordinates.z));

			while (coordinates.z > 15)
			{
				coordinates.z -= 5;
				vPlat->push_back(new StandartPlateforme(textureManager.getMidPlatTexture(), coordinates, coordinates.z));
			}

			sizeablePlatforms.push_back(vPlat);

		}
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

void GameLevel::draw(RenderWindow& mainWindow)
{
	for (vector<vector<StaticObject*>*>::iterator it = sizeablePlatforms.begin(); it != sizeablePlatforms.end(); ++it)
	{
		for (vector<StaticObject*>::iterator it2 = (*it)->begin(); it2 != (*it)->end(); ++it2)
		{
			mainWindow.draw(**it2);
		}
	}
}

bool GameLevel::checkPlatformCollision(Hero* hero)
{
	for (vector<vector<StaticObject*>*>::iterator it = sizeablePlatforms.begin(); it != sizeablePlatforms.end(); ++it)
	{
		for (vector<StaticObject*>::iterator it2 = (**it).begin(); it2 != (**it).end(); ++it2)
		{
			if ((*it2)->getIsSolid()
				&& hero->getPosition().y + hero->getTextureRect().height * 0.2f >= (*it2)->getPosition().y - 2
				&& hero->getPosition().y + hero->getTextureRect().height * 0.2f <= (*it2)->getPosition().y + 1
				&& hero->getPosition().x + hero->getFootSurface().left * 0.2f + hero->getFootSurface().width * 0.2f >(*it2)->getPosition().x
				&& hero->getPosition().x + hero->getFootSurface().left * 0.2f < (*it2)->getPosition().x + (*it2)->getTextureRect().width)
			{
				return true;
			}
		}
	}
	return false;
}
