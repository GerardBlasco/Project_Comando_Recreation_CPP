#pragma once
#include "Actor.h"
#include "EnemyState.h"
#include "Player.h"

class Enemy : public Actor
{
public:
	Enemy(class Scene* myScene, class Player* target);

	~Enemy();

	virtual void Update();

	virtual void OnCollisionEnter(class Collider* other); 

	Player* player; //puntero al player

protected:
<<<<<<< HEAD
	Vector2 direction; //Direccion del enemigo
	class Player* target; //Target es el player
	EnemyState state = EnemyState::Thinking;

=======
>>>>>>> e2ce48c5058a7f4c55e5b9ff70eb93312d127a75
	class Animator* animator;
	class Player* target;
	float time = 0.0f;
	float duration = 1.5f;
	float minDuration = 1.f;
	float maxDuration = 2.5f;

	Vector2 direction;
	EnemyState state = EnemyState::Thinking;

	float elapsed = 0.0f;
	float shootDistance = 300.f;
	float cooldown = 0.f;

	float moveSpeed = 200.f;

	virtual void SeekDirection();
	void RandomDuration();
};

