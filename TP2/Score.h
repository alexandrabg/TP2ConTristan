#pragma once
class Score
{
public:
	Score();
	~Score();
	void AddScore();
	int GetScore() const;
private:
	int score;
};

