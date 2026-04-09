#pragma once
#include "Actor.h"
#include <vector>
class Player : public Actor
{
public:
	int health;
	std::vector<class Weapon*> weapons;

	Player(class Scene* myScene);
	~Player();

	void LoseHealth(const int quantity);
	void PickUp();

private:
	int score;

	//void Update();

	void MoveHorizontal();
	void MoveVertical();
	void Shoot();
	void ShootAlternative();
};

