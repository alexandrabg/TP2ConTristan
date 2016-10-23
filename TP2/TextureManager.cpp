#include "TextureManager.h"
#include <SFML/Graphics.hpp>


TextureManager::TextureManager()
{
	heroSpriteSheet.loadFromFile("Assets\\hero1.png");
	plateformeSS.loadFromFile("Assets\\StandartPlateforme.png");
	plateformeSS2.loadFromFile("Assets\\StandartPlateforme2.png");
}


TextureManager::~TextureManager()
{
}

Texture& TextureManager::getHeroSpriteSheet()
{
	return heroSpriteSheet;
}

Texture& TextureManager::getPlateformeSS()
{
	return plateformeSS;
}

Texture& TextureManager::getPlateformeSS2()
{
	return plateformeSS2;
}
