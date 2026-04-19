#include "Sniper.h"
#include "Animator.h"
#include "Bullet.h"
#include "Game.h"
#include "RectangleCollider.h"

Sniper::Sniper(Scene* myScene, Player* target):Enemy(myScene, target)
{
	transform.position = Vector2(550, 50);

	tag = "Enemy";
	moveSpeed = 100.f;
	minDuration = 1.f;
	maxDuration = 2.f;
	shootDistance = 700.f;

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

	animator->GenerateAnimationsRange("sniper.png", "Walk", sheetOrder, 0, 0, 6, 8, 4, 40.f, 40.f);
	animator->GenerateAnimationsRange("sniper.png", "Idle", sheetOrder, 96, 0, 6, 8, 2, 40.f, 40.f, 0.5f);
	animator->LoadDirectionsOrder(directions);
}

void Sniper::Update() 
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

		if (time >= duration || playerDistance <= (shootDistance * 0.3f)) {
			state = EnemyState::Moving;
			RandomDuration();
			SeekDirection();
			time = 0;
		}

		break;

	case EnemyState::Moving:

		animator->SetCurrentIndex(Vector2::DirectionIndex(direction, 8));
		animationName = "Walk" + animator->GetDirection(animator->GetCurrentIndex());

		if (playerDistance <= (shootDistance * 0.3f)) {
			RandomDuration();
			SeekDirection();
			time = 0;
		}

		transform.position += direction * moveSpeed * Game::DeltaTime();

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

			Bullet* bullet = new Bullet(myScene, transform.position, target->transform.position);
			bullet->Tag("EnemyAttack");
			bullet->HitTag("Player");
			bullet->SetSpeed(1000.f);
			bullet->SetMaxDistance(600.f);
			myScene->LoadActor(bullet);

			cooldown = 0.9f;
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

void Sniper::OnCollisionEnter(Collider* other)
{
	if (other->Parent()->tag == "Attack") {

		player->AddScore(200); //sumamos al player una puntuacionn de 100 por cada enemigo matado

		toDelete = true; //lo eliminamos
	}
}

void Sniper::SeekDirection()
{
	Vector2 newDirection;

	Vector2 playerDirection = target->transform.position - transform.position;
	float playerDistance = playerDirection.Module();

	if (playerDistance <= (shootDistance * 0.3f)) {
		newDirection = transform.position - target->transform.position;
	}
	else {
		newDirection = target->transform.position - transform.position;
	}

	direction = newDirection.Normalized();
}
