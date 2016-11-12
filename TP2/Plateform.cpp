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

/// <summary>
/// Permet de retrouver les coordonnées de la plateforme à partir du fichier texte.
/// </summary>
/// <param name="coordinate">La coordonnée sous forme de string.</param>
/// <returns></returns>
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
