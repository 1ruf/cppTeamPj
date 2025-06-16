#pragma once
class Player
{
private:
	char _visual = '¡Ü';
	int _score;
	int _lives;
public:
	Player();
	char GetVisual() const { return _visual; }
	int GetScore() const { return _score; }
	int GetLives() const { return _lives; }

	void SetVisual(char visual) { _visual = visual; }
	void SetScore(int score) { _score = score; }
	void SetLives(int lives) { _lives = lives; }
	void IncreaseScore(int amount) { _score += amount; }
	void DecreaseLives(int amount) { _lives -= amount; }
};

inline Player::Player() : _score(0), _lives(3) {}

