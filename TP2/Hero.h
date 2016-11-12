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
	void setIsOnSolidGround(bool);
	void Jump();
	Vector2f getPositionHero() const;
	void setPositionHero(Vector2f);
	float getSpeed();
	IntRect& getFootSurface();

private:
	IntRect footSurface;
	int jumpHeight;
	float jumpingSpeed;
	float fallingSpeed;
	int jumpingFrameCounter;
	bool isJumping;
	bool isStillJumping;
	float speed;
	float startingHeight;
	float endingHeight;
	Vector2f positionHero;
	TextureManager* texture;
	Projectile* proj;
};

