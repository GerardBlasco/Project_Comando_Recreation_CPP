#include "MapChanger.h"
#include "RectangleCollider.h"
#include "Scene.h"
#include "Game.h"
#include "SecondScene.h"

MapChanger::MapChanger(Scene* myScene):Actor(myScene)
{
	AddComponent(new RectangleCollider(this, 200, 50));
}

void MapChanger::OnCollisionEnter(class Collider* other)
{
	if (other->Parent()->tag == "Player") {
		myScene->waitingSceneChange = true;
		myScene->nextScene = new SecondScene(myScene->GI);
	}
}
