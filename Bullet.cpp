#include "Bullet.h"
#include "Sprite.h"
#include "Weapon.h"
#include "RectangleCollider.h"
#include "Game.h"

Bullet::Bullet(Scene* myScene, Vector2 originPos, Vector2 targetPos):Weapon(myScene, originPos, targetPos)
{
	speed = 700.f;

	transform.position = originPos;

	AddComponent(new Sprite(this, "bullet.png", 14));
	AddComponent(new RectangleCollider(this, 14, 14, Color(255, 0, 0, 255)));

	direction = targetPos - originPos;

	direction.Normalize();
}

void Bullet::Move()
{
	transform.position = transform.position + (direction * speed * Game::DeltaTime());

	float distance = (transform.position - originPos).Module();

	if (distance >= maxDistance) {
		toDelete = true;
	}
}

void Bullet::OnCollisionEnter(Collider* other)
{
	if (other->Parent()->tag == hitTag) {
		toDelete = true;
	}
}
