#include "Scene.h"
#include "Actor.h"
Scene::Scene(GraphicsInterface* GI)
{
	this->GI = GI;
}

Scene::~Scene()
{
}

void Scene::Update()
{
	for(Actor* actor : actors) {
		actor->Update();
	}

	for (int i = 0; i < actors.size(); ) {
		if (actors[i]->ToDelete()) {
			delete actors[i];
			actors.erase(actors.begin() + i);
		}
		else {
			i++;
		}
	}

	for (Actor* actor : actorsToAdd) {
		actors.push_back(actor);
	}

	actorsToAdd.clear();
}

void Scene::Render()
{
	for (Actor* actor : actors) {
		actor->Render();
	}
}

void Scene::LoadActor(Actor* actor)
{
	actorsToAdd.push_back(actor);
}
