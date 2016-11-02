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
			coordinates.y = 480 - coordinates.y;

			staticObjects.push_back(new StandartPlateforme(textureManager.getPlateformeSS2(), coordinates));
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
