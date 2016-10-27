#pragma once
#include "StaticObject.h"
#include "Constantes.h"
#include <iostream>
#include <fstream>
#include <sstream>

class Plateform :
	public StaticObject
{
public:
	Plateform();
	~Plateform();

private:
	vector<Vector3f*> tabPlateforms;
	vector<int> tabPlatformLengths;
	void OpenFile(ifstream filename);
	Vector3f ParseCoordinates(string coordinate);
	Vector3f platformCoordinate;
	Vector3f coordinateNumber;
	int longueur;
	int count = 0;
};