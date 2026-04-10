#include "Actor.h"
#include "Scene.h"
#include "Component.h"

Actor::Actor(Scene* myScene)
{
	this->myScene = myScene;
}

void Actor::Update()
{
	for (Component* component : components) {
		component->Update();
	}
}

void Actor::Render()
{
	for (Component* component : components) {
		component->Render();
	}
}

void Actor::AddComponent(Component* newComponent)
{
	components.push_back(newComponent);
}

bool Actor::ToDelete()
{
	return toDelete;
}
