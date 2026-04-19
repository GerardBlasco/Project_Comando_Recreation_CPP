#include "VictoryChanger.h"
#include "Scene.h"
#include "RectangleCollider.h"
#include "VictoryScene.h"

VictoryChanger::VictoryChanger(Scene* myScene):MapChanger(myScene)
{
}

void VictoryChanger::OnCollisionEnter(class Collider* other)
{
	if (other->Parent()->tag == "Player") {
		//InputSystem::ClearListeners();
		//InputSystem::ClearMaps();

		myScene->waitingSceneChange = true;
		myScene->nextScene = new VictoryScene(myScene->GI);
	}
}
