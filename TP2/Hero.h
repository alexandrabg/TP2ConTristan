#pragma once
#include "Character.h"
class Hero :
	public Character
{
public:
	Hero(Texture&);
	~Hero();
	
	void move(float offsetX, float offsetY);
	void update();
	void setIsOnSolidGround(bool);
	void Jump();
	Vector2f getPositionHero() const;
	void setPositionHero(Vector2f);
	float getSpeed();

private:
	int jumpingFrameCounter;
	bool isJumping;
	float speed;
	float startingHeight;
	float endingHeight;
	Vector2f positionHero;
};

