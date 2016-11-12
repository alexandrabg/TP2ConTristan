#include "Score.h"


Score::Score() : score(0)
{
}


Score::~Score()
{
}

/// <summary>
/// Ajoute le score à chaque fois que l'ennemi ramasse un collectible ou tue un ennemi
/// </summary>
void Score::AddScore()
{
	score += 100;
}

int Score::GetScore() const
{
	return score;
}


