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
	

private:
	Texture bgTexture;
	Texture heroSpriteSheet;
	Texture plateformeSS;
	Texture plateformeSS2;
};

