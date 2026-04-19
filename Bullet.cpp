#include "Bullet.h"
#include "Sprite.h"
#include "Weapon.h"
#include "RectangleCollider.h"
#include "Animation.h"
#include "Game.h"
#include "Explosion.h"

Bullet::Bullet(Scene* myScene, Vector2 originPos, Vector2 targetPos):Weapon(myScene, originPos, targetPos)
{
	speed = 700.f;

	transform.position = originPos;

	AddComponent(new Sprite(this, "bullet.png", 14));

	RectangleCollider* collider = new RectangleCollider(this, 14, 14, Color(255, 0, 0, 255));
	collider->IsTrigger(true);
	AddComponent(collider);

	direction = targetPos - originPos;

	direction.Normalize();
}

void Bullet::Move()
{
	transform.position = transform.position + (direction * speed * Game::DeltaTime());

	float distance = (transform.position - originPos).Module();

	if (distance >= maxDistance) {
		toDelete = true;
		Weapon* explosion = new Explosion(myScene, transform.position);
		explosion->Tag(tag);
		explosion->HitTag(hitTag);

		Animation* animation = new Animation(explosion, "bullet_explosion.png", 3, 1, 40, 40, 0.05f);
		animation->LoadFrames(0, 0, 3);
		animation->PlayOnce();

		explosion->AddComponent(animation);
		myScene->LoadActor(explosion);
	}
}

void Bullet::OnCollisionEnter(Collider* other)
{
	if (other->Parent()->tag == hitTag) {
		toDelete = true;
		Weapon* explosion = new Explosion(myScene, transform.position);
		explosion->Tag(tag);
		explosion->HitTag(hitTag);

		Animation* animation = new Animation(explosion, "bullet_explosion.png", 3, 1, 40, 40, 0.05f);
		animation->LoadFrames(0, 0, 3);
		animation->PlayOnce();

		explosion->AddComponent(animation);
		myScene->LoadActor(explosion);
	}
}

void Bullet::SetMaxDistance(float maxDistance)
{
	this->maxDistance = maxDistance;
}
