#include "Enemy.h"
#include "Sprite.h"
#include "RectangleCollider.h"
#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "Granade.h";

Enemy::Enemy(Scene* myScene, Player* target):Actor(myScene)
{
	this->target = target;

	transform.position = Vector2(400, 200);
	tag = "Enemy";

	AddComponent(new Sprite(this, "enemy.png", 30, 50));
	AddComponent(new RectangleCollider(this, 30, 50, Color(0, 255, 255, 255)));
}

void Enemy::Update()
{
	time += Game::DeltaTime();

	float playerDistance = (target->transform.position - transform.position).Module();

	switch (state) {
	case EnemyState::Thinking:

		if (playerDistance <= shootDistance) {
			state = EnemyState::Shooting;
			RandomDuration();
			time = 0;
		}

		if (time >= duration) {
			state = EnemyState::Moving;
			RandomDuration();
			SeekDirection();
			time = 0;
		}

		break;
		
	case EnemyState::Moving:

		transform.position += direction * 200.f * Game::DeltaTime();

		if (time >= duration) {
			state = EnemyState::Thinking;
			RandomDuration();
			time = 0;
		}

		break;
		
	case EnemyState::Shooting:

		cooldown -= Game::DeltaTime();

		if (cooldown <= 0) {
			Granade* bullet = new Granade(myScene, transform.position, target->transform.position);
			bullet->Tag("EnemyAttack");
			bullet->HitTag("Player");
			myScene->LoadActor(bullet);

			cooldown = 0.6f;
		}

		if (time >= duration || playerDistance > shootDistance) {
			state = EnemyState::Moving;
			RandomDuration();
			SeekDirection();
			time = 0;
		}

		break;
	}
}

void Enemy::OnCollisionEnter(Collider* other)
{
	if (other->Parent()->tag == "Attack") {
		toDelete = true;
	}
}

void Enemy::SeekDirection()
{
	Vector2 newDirection = target->transform.position - transform.position;

	direction = newDirection.Normalized();
}

void Enemy::RandomDuration()
{
	duration = minDuration + (rand() / (float)RAND_MAX) * (maxDuration - minDuration);
}
