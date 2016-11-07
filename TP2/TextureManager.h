#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	Texture& getBgTexture();
	Texture& getHeroSpriteSheet();
	Texture& getPlateformeSS();
	Texture& getPlateformeSS2();
	Texture& getBirdTexture();
	Texture& getSnailTexture();
	Texture& getManTexture();
	Texture& getMtnDewTexture();
	Texture& getSaleTexture();
	Texture& getLeftPlatTexture();
	Texture& getMidPlatTexture();
	Texture& getRightPlatTexture();
	Texture& getCheetosTexture();

private:
	Texture bgTexture;
	Texture heroSpriteSheet;
	Texture plateformeSS;
	Texture plateformeSS2;
	Texture birdTexture;
	Texture snailTexture;
	Texture manTexture;
	Texture mtnDewTexture;
	Texture saleTexture;
	Texture leftPlatTexture;
	Texture rightPlatTexture;
	Texture midPlatTexture;
	Texture cheetosTexture;
};

