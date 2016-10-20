#pragma once
#include "SpriteMaker.h"
#include <SFML/Graphics.hpp>
#include "Constantes.h"

using namespace sf;

class Character
	//public SpriteMaker
{
public:
	Character();
	Texture heroTexture;
	Sprite heroSprite;
	Sprite GetSprite() const;
	Vector2f GetPositionHero() const;
	void Move();
	~Character();

private:
	Vector2f positionHero;

};

