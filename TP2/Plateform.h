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
	vector<Vector2f*> tabPlateforms;
	void OpenFile(ifstream filename);
	Vector2f ParseCoordinates(string coordinate);
	Vector2f platformCoordinate;
	Vector2f coordinateNumber;
	int count = 0;
};