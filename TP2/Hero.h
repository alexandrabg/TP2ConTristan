#pragma once
#include "Character.h"
#include "Projectile.h"
#include "TextureManager.h"

class Hero :
	public Character
{
public:
	Hero(Texture&, IntRect foot);
	~Hero();
	
	void move(float offsetX, float offsetY);
	void update();
	void Jump();
	Vector2f getPositionHero() const;
	void setPositionHero(Vector2f);
	float getSpeed();
	int getAS();

private:
	int jumpHeight;
	float jumpingSpeed;
	int jumpingFrameCounter;
	bool isJumping;
	bool isStillJumping;
	float speed;
	float startingHeight;
	float endingHeight;
	Vector2f positionHero;
	TextureManager* texture;
	Projectile* proj;
	int attackSpeed;
};

