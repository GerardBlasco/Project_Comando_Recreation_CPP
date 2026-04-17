#include "Granade.h"
#include "Sprite.h"
#include "Game.h"
#include "RectangleCollider.h"
#include "Animation.h"
#include "Explosion.h"

Granade::Granade(Scene* myScene, Vector2 originPos, Vector2 targetPos):Weapon(myScene, originPos, targetPos)
{
	AddComponent(new Sprite(this, "granade.png", 14));
	
	transform.position = originPos;

	duration = 1.f;

	Vector2 mid = (originPos + targetPos) * 0.5f;
	middlePos = mid + Vector2(0, -250.f);

	elapsed = 0.0f;
	time = 0.0f;
}

void Granade::Move()
{
	elapsed += Game::DeltaTime() * 1.f;
	time = elapsed / duration;

	if (time >= 1.0f) {
		time = 1.0f;
		toDelete = true;
		Weapon* explosion = new Explosion(myScene, transform.position);
		explosion->AddComponent(new RectangleCollider(explosion, 40, 40, Color(255, 255, 0, 255)));
		explosion->Tag(tag);
		explosion->HitTag(hitTag);

		Animation* animation = new Animation(explosion, "explosion.png", 3, 1, 40, 40, 0.05f);
		animation->LoadFrames(0, 0, 3);
		animation->PlayOnce();

		explosion->AddComponent(animation);
		myScene->LoadActor(explosion);
	}

	transform.position = Vector2::Bezier(originPos, middlePos, targetPos, time);
}
