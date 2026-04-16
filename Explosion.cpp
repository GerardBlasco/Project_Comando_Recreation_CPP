#include "Explosion.h"
#include "Sprite.h"
#include "RectangleCollider.h"
#include "Game.h"

Explosion::Explosion(Scene* myScene, Vector2 position):Weapon(myScene, position, position)
{
	tag = "Attack";
	transform.position = position;
	AddComponent(new Sprite(this, "explosion.png", 40));
	AddComponent(new RectangleCollider(this, 40, 40, Color(255, 255, 0, 255)));
}

void Explosion::Update()
{
	elapsed += Game::DeltaTime() * 1.f;
	time = elapsed / duration;

	if (time >= duration) {
		toDelete = true;
	}
}
