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

private:
	Vector2 direction;
	class Player* target;
	EnemyState state = EnemyState::Thinking;

	class Animator* animator;

	float time = 0.0f;
	float duration = 1.5f;
	float minDuration = 1.f;
	float maxDuration = 2.5f;
	float elapsed = 0.0f;
	float shootDistance = 300.f;
	float cooldown = 0.f;

	void SeekDirection();
	void RandomDuration();
};

