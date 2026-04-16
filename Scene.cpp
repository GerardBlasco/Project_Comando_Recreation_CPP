#include "Scene.h"
#include "Actor.h"
#include "RectangleCollider.h"
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
		actor->InternalUpdate();
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

	CheckCollisions();
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

void Scene::LoadCollider(RectangleCollider* collider)
{
	existingColliders.push_back(collider);
}

void Scene::RemoveCollider(RectangleCollider* collider)
{
	for (int i = 0; i < existingColliders.size(); i++) {
		if (existingColliders[i] == collider) {
			existingColliders.erase(existingColliders.begin() + i);
			return;
		}
	}
}

void Scene::CheckCollisions()
{
	for (int i = 0; i < existingColliders.size(); i++) {
		RectangleCollider* a = existingColliders[i];
		if (!a) continue;

		for (int j = i + 1; j < existingColliders.size(); j++) {
			RectangleCollider* b = existingColliders[j];
			if (!b) continue;

			if (a->CheckIfCollided(b)) {
				//std::cout << "Collided!" << std::endl;
				a->Parent()->OnCollisionEnter(b);
				b->Parent()->OnCollisionEnter(a);
			}
		}
	}
}
