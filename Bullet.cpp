#include "Bullet.h"
#include "Sprite.h"
#include "Weapon.h"
#include "Game.h"

Bullet::Bullet(Scene* myScene, Vector2 originPos, Vector2 targetPos):Weapon(myScene, originPos, targetPos)
{
	speed = 700.f;

	AddComponent(new Sprite(this, "bullet.png", 14));

	transform.position = originPos;

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
