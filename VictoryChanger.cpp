#include "VictoryChanger.h"
#include "Scene.h"
#include "RectangleCollider.h"

VictoryChanger::VictoryChanger(Scene* myScene):MapChanger(myScene)
{
}

void VictoryChanger::OnCollisionEnter(class Collider* other)
{
	if (other->Parent()->tag == "Player") {
		
	}
}
