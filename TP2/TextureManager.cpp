#include "TextureManager.h"
#include <SFML/Graphics.hpp>


TextureManager::TextureManager()
{
	bgTexture.loadFromFile("Assets\\TikiRossBG.png");
	heroSpriteSheet.loadFromFile("Assets\\hero1.png");
	plateformeSS.loadFromFile("Assets\\StandartPlateforme.png");
	plateformeSS2.loadFromFile("Assets\\StandartPlateforme2.png");
	birdTexture.loadFromFile("Assets\\bird.png");
	snailTexture.loadFromFile("Assets\\snail.png");
	manTexture.loadFromFile("Assets\\man.png");
	mtnDewTexture.loadFromFile("Assets\\mtnDew.png");
	saleTexture.loadFromFile("Assets\\sale.png");
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

Texture& TextureManager::getBgTexture()
{
	return bgTexture;
}

Texture& TextureManager::getBirdTexture()
{
	return birdTexture;
}

Texture& TextureManager::getSnailTexture()
{
	return snailTexture;
}

Texture& TextureManager::getManTexture()
{
	return manTexture;
}

Texture& TextureManager::getMtnDewTexture()
{
	return mtnDewTexture;
}

Texture& TextureManager::getSaleTexture()
{
	return saleTexture;
}



