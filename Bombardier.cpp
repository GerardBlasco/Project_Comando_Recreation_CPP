#include "Bombardier.h"
#include "RectangleCollider.h"
#include "Animator.h"
#include "Granade.h"
#include "Game.h"
#include "AudioManager.h"

Bombardier::Bombardier(Scene* myScene, Player* target):Enemy(myScene, target)
{
	transform.position = Vector2(500, 100);

	tag = "Enemy";
	moveSpeed = 150.f;
	minDuration = 2.f;
	maxDuration = 3.5f;

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

	animator->GenerateAnimationsRange("bombardier.png", "Walk", sheetOrder, 0, 0, 6, 8, 4, 40.f, 40.f);
	animator->GenerateAnimationsRange("bombardier.png", "Idle", sheetOrder, 96, 0, 6, 8, 2, 40.f, 40.f, 0.5f);
	animator->LoadDirectionsOrder(directions);
}

void Bombardier::Update()
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

			Granade* granade = new Granade(myScene, transform.position, target->transform.position);
			granade->Tag("EnemyAttack");
			granade->HitTag("Player");
			myScene->LoadActor(granade);

			cooldown = 0.7f;
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

void Bombardier::OnCollisionEnter(Collider* other)
{
	if (other->Parent()->tag == "Attack") {

		//Sonido
		AudioManager::instance().playSFX("death_enemy_sound.mp3");
		AudioManager::instance().setSFXVolume(30);

		player->AddScore(200); //sumamos al player una puntuacionn de 100 por cada enemigo matado

		toDelete = true; //lo eliminamos
	}
}
