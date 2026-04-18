#include "Pickeable.h"
#include "Animation.h"
#include "RectangleCollider.h"

Pickeable::Pickeable(Scene* myScene):Actor(myScene)
{
	transform.position = Vector2(600, 600);

	RectangleCollider* collider = new RectangleCollider(this, 38, 38, Color(0, 0, 255, 255));
	collider->IsTrigger(true);
	AddComponent(collider);

	Animation* animation = new Animation(this, "granade_stack.png", 2, 1, 38, 38, 0.3f);
	animation->LoadFrames(0, 0, 2);
	AddComponent(animation);
}

void Pickeable::OnCollisionEnter(Collider* other)
{
	if (other->Parent()->tag == "Player") {
		toDelete = true;
	}
}
