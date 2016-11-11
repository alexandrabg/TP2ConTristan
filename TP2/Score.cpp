#include "Score.h"


Score::Score()
{
	score = 0;
}


Score::~Score()
{
}

void Score::AddScore()
{
	score += 100;
}

int Score::GetScore() const
{
	return score;
}


