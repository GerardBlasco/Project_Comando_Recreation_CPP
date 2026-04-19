#pragma once
#include "Actor.h"
#include "EnemyState.h"
#include "Player.h"

class Enemy : public Actor
{
public:
	Enemy(class Scene* myScene, class Player* target);

	virtual void Update();

	virtual void OnCollisionEnter(class Collider* other);

	Player* player; //puntero al player

protected:
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

