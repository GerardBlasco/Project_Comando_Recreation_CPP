#include "Scene.h"
#include "Actor.h"
#include "RectangleCollider.h"
#include "Game.h"
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

	for (int i = 0; i < existingColliders.size(); ) {
		if (existingColliders[i]->ToDelete()) {
			existingColliders.erase(existingColliders.begin() + i);
		}
		else {
			i++;
		}
	}

	if (waitingSceneChange) {
		Game::ChangeScene(nextScene);
		return;
	}
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

void Scene::HandleInput()
{
}

void Scene::ChangeToScene()
{
}

bool Scene::ColliderStillExists(RectangleCollider* collider)
{
	if (!collider || collider->ToDelete()) return false;
	return std::find(existingColliders.begin(), existingColliders.end(), collider) != existingColliders.end();
}

std::vector<Actor*> Scene::GetAllActors()
{
	return actors;
}

void Scene::CheckCollisions()
{
	for (RectangleCollider* collider : existingColliders) {
		if (collider && !collider->ToDelete()) {
			collider->SetPreviousCollisions();
		}
	}

	for (int i = 0; i < existingColliders.size(); i++) {
		RectangleCollider* a = existingColliders[i];
		if (!a || a->ToDelete()) continue;

		for (int j = i + 1; j < existingColliders.size(); j++) {
			RectangleCollider* b = existingColliders[j];
			if (!b || b->ToDelete()) continue;

			if (a->CheckIfCollided(b)) {
				
				a->currentCollisions.push_back(b);
				b->currentCollisions.push_back(a);

				if (!a->AlreadyColliding(b)) {
					a->Parent()->OnCollisionEnter(b);
					b->Parent()->OnCollisionEnter(a);
				}
				else {
					//!a->IsRigid() ? a->Parent()->OnCollisionStay(b) : a->PushAway(b->Parent());
					//!b->IsRigid() ? b->Parent()->OnCollisionStay(a) : b->PushAway(a->Parent());
					a->Parent()->OnCollisionStay(b);
					b->Parent()->OnCollisionStay(a);
				}

				a->SolveCollision(b);
			}
		}
	}

	for (RectangleCollider* collider : existingColliders) {
		if (collider && !collider->ToDelete()) {
			for (RectangleCollider* previous : collider->previousCollisions) {

				if (!ColliderStillExists(previous)) {
					continue;
				}

				if (std::find(collider->currentCollisions.begin(), collider->currentCollisions.end(), previous) == collider->currentCollisions.end()) {
					collider->Parent()->OnCollisionExit(previous);
				}
			}
		}
	}
}
