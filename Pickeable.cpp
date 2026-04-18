#include "Pickeable.h"
#include "Animation.h"
#include "RectangleCollider.h"

Pickeable::Pickeable(Scene* myScene, Player* target):Actor(myScene)
{
	this->player = target; //se guarda el player

	transform.position = Vector2(600, 600);
	AddComponent(new RectangleCollider(this, 38, 38, Color(0, 0, 255, 255)));

	Animation* animation = new Animation(this, "granade_stack.png", 2, 1, 38, 38, 0.3f);
	animation->LoadFrames(0, 0, 2);
	AddComponent(animation);
}

void Pickeable::OnCollisionEnter(Collider* other)
{
	if (other->Parent()->tag == "Player") { //si colisiona con algo con ese tag
		player->SetGranadesQuantity(5); //llama al metodo
		toDelete = true; //eliminala
	}
}
