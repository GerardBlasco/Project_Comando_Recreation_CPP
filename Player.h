#pragma once
#include "Actor.h"
#include <vector>
#include <map>
class Player : public Actor
{
public:
	int health;
	std::vector<class Weapon*> weapons;

	Player(class Scene* myScene);
	//~Player();

	void LoseHealth(const int quantity);
	void PickUp();

private:
	int score;

	class Animator* animator;
	int currentIndex;

	std::map<int, std::string> directions = {{0, "Right"}, {1, "DownRight"}, {2, "Down"}, {3, "DownLeft"}, {4, "Left"}, {5, "UpLeft"}, {6, "Up"}, {7, "UpRight"} };
	std::vector<std::string> order = { "Down", "Up", "Left", "Right", "DownLeft", "DownRight", "UpLeft", "UpRight" };
	std::string currentAnimation;

	virtual void Update();

	void MoveHorizontal();
	void MoveVertical();
	void Shoot();
	void ShootAlternative();
	int DirectionIndex(Vector2 direction);
};

