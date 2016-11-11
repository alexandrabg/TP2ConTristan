#pragma once
class Randomizer
{
public:
	Randomizer();
	~Randomizer();
	Randomizer* GetInstance();
private:
	Randomizer* instance;
};

