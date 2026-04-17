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

	std::string currentAnimation;

	virtual void Update();

	void MoveHorizontal();
	void MoveVertical();
	void Shoot();
	void ShootAlternative();
};

