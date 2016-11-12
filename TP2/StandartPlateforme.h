#pragma once
#include "StaticObject.h"
class StandartPlateforme : 
	public StaticObject
{
public:
	StandartPlateforme(const Texture&, const Vector3f);
	StandartPlateforme(const Texture&, const Vector3f, const int offsetX);
	~StandartPlateforme();
};

