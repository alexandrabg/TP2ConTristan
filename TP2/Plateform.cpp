#include "Plateform.h"


Plateform::Plateform()
{
	tabPlateforms[NB_PLATFORMS];
	tabPlatformLengths[NB_PLATFORMS];
}


Plateform::~Plateform()
{
}

void Plateform::OpenFile(ifstream filename)
{
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
			coordinateNumber = ParseCoordinates(coordinate);
			tabPlateforms[count] = &coordinateNumber;
			count++;
		}
	}
}

Vector3f Plateform::ParseCoordinates(string coordinate)
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
	ss >> number;
	platformCoordinate.z = number;

	return platformCoordinate;
}

