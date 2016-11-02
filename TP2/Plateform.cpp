#include "Plateform.h"
#include "StandartPlateforme.h"


Plateform::Plateform()
{
	tabPlateforms[NB_PLATFORMS];
	//tabPlatformLengths[NB_PLATFORMS];
}


Plateform::~Plateform()
{
}

void Plateform::OpenFile(ifstream filename)
{
}

Vector2f Plateform::ParseCoordinates(string coordinate)
{
	for (size_t i = 0; i < strlen(coordinate.c_str()); i++)
	{
		if (coordinate[i] == ',')
			coordinate[i] = ' ';
	}
	stringstream ss(coordinate);

	int number;
	ss >> number;
	platformCoordinate.x = number;
	ss >> number;
	platformCoordinate.y = number;

	return platformCoordinate;
}

vector<StaticObject*> Plateform::getVectPlateform()
{
	return vectPlateforms;
}
