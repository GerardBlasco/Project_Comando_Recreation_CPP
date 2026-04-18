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
	void AddScore(int amount); //Metodo para añadir puntuacion
	int GetScore(); //Metodo que devuelve la puntuacion

private:
	int score; //Puntuacion del player

	class Animator* animator;

	std::string currentAnimation;

	virtual void Update();

	void MoveHorizontal();
	void MoveVertical();
	void Shoot();
	void ShootAlternative();
};

