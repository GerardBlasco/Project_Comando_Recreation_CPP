#include "Pickeable.h"
#include "Sprite.h"
#include "RectangleCollider.h"

Pickeable::Pickeable(Scene* myScene):Actor(myScene)
{
	transform.position = Vector2(600, 600);
	AddComponent(new Sprite(this, "granade_stack.png", 38, 38));
	AddComponent(new RectangleCollider(this, 38, 38, Color(0, 0, 255, 255)));
}

void Pickeable::OnCollisionEnter(Collider* other)
{
	if (other->Parent()->tag == "Player") {
		toDelete = true;
	}
}
