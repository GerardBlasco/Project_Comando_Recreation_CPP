#pragma once
#include "Actor.h"
#include <vector>
#include <map>
class Player : public Actor
{
public:
	int health;

	//std::vector<class Weapon*> weapons;
	int granadesLeft;

	Player(class Scene* myScene);
	//~Player();

	void LoseHealth(const int quantity);
	void PickUp();
	void AddScore(int amount); //Metodo para añadir puntuacion
	int GetScore(); //Metodo que devuelve la puntuacion
	virtual void OnCollisionEnter(class Collider* other); //Cuando le colisiona algo
	int GetHealth(); //Devuelve la vida
	void SetGranadesQuantity(int quantity); //setear la cantidad de granadas
	int GetGranades(); //devuelve la cantidad de granadas
	void LoseGranade(); //metodo para quitar granadas

private:
	int score; //Puntuacion del player
	bool dead = false;

	class Animator* animator;

	std::string currentAnimation;

	virtual void Update();

	void MoveHorizontal();
	void MoveVertical();
	void Shoot();
	void ShootAlternative();
};

