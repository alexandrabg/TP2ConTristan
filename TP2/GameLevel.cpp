#include "GameLevel.h"
#include "SteamSale.h"


GameLevel::GameLevel()
{
	pStaticObjects = &staticObjects;
	mainView = new View(FloatRect(0, 0, LARGEUR, HAUTEUR));
	staticObjects.push_back(new StaticObject(textureManager.getBgTexture(), IntRect(0,0,0,0), false));
	vSale = new vector<StaticObject*>;
	vMtnDew = new vector<StaticObject*>;
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
	for (vector<StaticObject*>::iterator it = vSale->begin(); it != vSale->end(); ++it)
	{
		delete *it;
	}
	for (vector<StaticObject*>::iterator it = vMtnDew->begin(); it != vMtnDew->end(); ++it)
	{
		delete *it;
	}
}

void GameLevel::OpenLevelFile()
{
	ifstream filename;
	ifstream filename2;
	filename.open("Assets\\Platforms.txt");
	filename2.open("Assets\\sale.txt");
	if (!filename || !filename2)
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
	if (filename2)
	{
		string coordinate = "";
		while (filename2 >> coordinate)
		{
			for (size_t i = 0; i < strlen(coordinate.c_str()); i++)
			{
				if (coordinate[i] == ',')
					coordinate[i] = ' ';
			}
			stringstream ss(coordinate);

			Vector2f coordinates;
			ss >> coordinates.x;
			ss >> coordinates.y;
			coordinates.y = 470 - coordinates.y;

			vSale->push_back(new SteamSale(textureManager.getSaleTexture(), coordinates.x, coordinates.y));
		}
	}
	vMtnDew->push_back(new MoutainDew(textureManager.getMtnDewTexture(), 950, 390));
	vMtnDew->push_back(new MoutainDew(textureManager.getMtnDewTexture(), 1740, 160));
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
	for (vector<StaticObject*>::iterator it = vSale->begin(); it != vSale->end(); ++it)
	{
		mainWindow.draw(**it);
	}
	for (vector<StaticObject*>::iterator it = vMtnDew->begin(); it != vMtnDew->end(); ++it)
	{
		mainWindow.draw(**it);
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
