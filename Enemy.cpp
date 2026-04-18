#include "Enemy.h"
#include "Animator.h"
#include "RectangleCollider.h"
#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "Granade.h";

Enemy::Enemy(Scene* myScene, Player* target):Actor(myScene)
{
	this->player = target; //se guarda el player
	this->target = target;

	transform.position = Vector2(400, 200);
	tag = "Enemy";

	AddComponent(new RectangleCollider(this, 40, 40, Color(0, 255, 255, 255)));

	animator = new Animator(this);
	AddComponent(animator);

	std::map<int, std::string> directions =
	{
		{0, "Right"},
		{1, "DownRight"},
		{2, "Down"},
		{3, "DownLeft"},
		{4, "Left"},
		{5, "UpLeft"},
		{6, "Up"},
		{7, "UpRight"}
	};

	std::vector<std::string> sheetOrder =
	{
		"Down",
		"Up",
		"Left",
		"Right",
		"DownLeft",
		"DownRight",
		"UpLeft",
		"UpRight"
	};

	animator->GenerateAnimationsRange("enemy.png", "Walk", sheetOrder, 0, 0, 6, 8, 4, 40.f, 40.f);
	animator->GenerateAnimationsRange("enemy.png", "Idle", sheetOrder, 96, 0, 6, 8, 2, 40.f, 40.f, 0.5f);
	animator->LoadDirectionsOrder(directions);
}

void Enemy::Update()
{
	time += Game::DeltaTime();

	Vector2 playerDirection = target->transform.position - transform.position;
	float playerDistance = playerDirection.Module();

	std::string animationName;

	switch (state) {
	case EnemyState::Thinking:

		animator->SetCurrentIndex(Vector2::DirectionIndex(playerDirection, 8));
		animationName = "Idle" + animator->GetDirection(animator->GetCurrentIndex());

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

		animator->SetCurrentIndex(Vector2::DirectionIndex(direction, 8));
		animationName = "Walk" + animator->GetDirection(animator->GetCurrentIndex());

		transform.position += direction * 200.f * Game::DeltaTime();

		if (time >= duration) {
			state = EnemyState::Thinking;
			RandomDuration();
			time = 0;
		}

		break;
		
	case EnemyState::Shooting:

		animator->SetCurrentIndex(Vector2::DirectionIndex(playerDirection, 8));
		animationName = "Idle" + animator->GetDirection(animator->GetCurrentIndex());

		cooldown -= Game::DeltaTime();

		if (cooldown <= 0) {

			float shootProbability = rand() / (float)RAND_MAX;

			if (shootProbability >= 0.15f) {
				Bullet* bullet = new Bullet(myScene, transform.position, target->transform.position);
				bullet->Tag("EnemyAttack");
				bullet->HitTag("Player");
				myScene->LoadActor(bullet);

				cooldown = 0.3f;
			}
			else {
				Granade* granade = new Granade(myScene, transform.position, target->transform.position);
				granade->Tag("EnemyAttack");
				granade->HitTag("Player");
				myScene->LoadActor(granade);

				cooldown = 0.7f;
			}
		}

		if (time >= duration || playerDistance > shootDistance) {
			state = EnemyState::Moving;
			RandomDuration();
			SeekDirection();
			time = 0;
		}

		break;
	}

	if (animator->GetCurrentAnimationName() != animationName) {
		animator->SetCurrentAnimationName(animationName);
		animator->PlayAnimation(animationName);
	}
}

void Enemy::OnCollisionEnter(Collider* other)
{
	if (other->Parent()->tag == "Attack") {

		player->AddScore(100); //sumamos al player una puntuacionn de 100 por cada enemigo matado

		toDelete = true; //lo eliminamos
		
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
