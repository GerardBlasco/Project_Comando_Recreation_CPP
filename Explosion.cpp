#include "Explosion.h"
#include "Animation.h"
#include "RectangleCollider.h"
#include "Game.h"

Explosion::Explosion(Scene* myScene, Vector2 position):Weapon(myScene, position, position)
{
	tag = "Attack";
	transform.position = position;
	/*Animation* animation = new Animation(this, "explosion.png", 3, 1, 40, 40, 0.05f);
	animation->LoadFrames(0, 0, 3);
	animation->PlayOnce();
	AddComponent(animation);*/
}

void Explosion::Update()
{
	elapsed += Game::DeltaTime() * 1.f;
	time = elapsed / duration;

	if (time >= duration) {
		toDelete = true;
	}
}
