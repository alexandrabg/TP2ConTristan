#pragma once
#include "StaticObject.h"
#include "Constantes.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "TextureManager.h"

class Plateform :
	public StaticObject
{
public:
	Plateform();
	~Plateform();
	vector<StaticObject*> getVectPlateform();

private:
	vector<Vector3f*> tabPlateforms;
	vector<StaticObject*> vectPlateforms;
	void OpenFile(ifstream filename);
	Vector2f ParseCoordinates(string coordinate);
	Vector2f platformCoordinate;
	Vector2f coordinateNumber;
	TextureManager textureManager;
	int longueur;
	int count = 0;
};
