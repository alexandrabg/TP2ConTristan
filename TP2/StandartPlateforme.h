#pragma once
#include "StaticObject.h"
class StandartPlateforme : 
	public StaticObject
{
public:
	StandartPlateforme(Texture&, Vector3f);
	StandartPlateforme(Texture&, Vector3f, int offsetX);
	~StandartPlateforme();
};

