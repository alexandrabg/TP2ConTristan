#include "Character.h"


Character::Character()
{
	heroTexture.loadFromFile("Assets\\hero.png");
	heroSprite.setTexture(heroTexture);
	heroSprite.setScale(0.3, 0.3);
	heroSprite.setOrigin(0, 0);
	heroSprite.setPosition(LARGEUR / 2, HAUTEUR / 2);
	positionHero = heroSprite.getPosition();
}

Sprite Character::GetSprite() const
{
	return heroSprite;
}

Vector2f Character::GetPositionHero() const
{
	return positionHero;
}

void Character::Move()
{
	if (Keyboard::isKeyPressed(Keyboard::A) && heroSprite.getPosition().x - heroTexture.getSize().x / 2 >= 0)
	{
		positionHero.x = -SPEED;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		positionHero.x = SPEED;
	}
	else
		positionHero.x = 0;
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		positionHero.y = -SPEED;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		positionHero.y = SPEED;
	}
	else
		positionHero.y = 0;
}

Character::~Character()
{
}
