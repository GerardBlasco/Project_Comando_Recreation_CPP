#include "Actor.h"
#include "Scene.h"
#include "Component.h"
#include "Collider.h"

Actor::Actor(Scene* myScene)
{
	this->myScene = myScene;
}

Actor::~Actor()
{
	for (Component* c : components) {
		delete c;
	}
	components.clear();
}

void Actor::Update()
{
	
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

void Actor::ToDelete(bool b)
{
	toDelete = b;
}

void Actor::Tag(std::string tag)
{
	this->tag = tag;
}

void Actor::OnCollisionEnter(Collider* other)
{
}

void Actor::InternalUpdate()
{
	for (Component* component : components) {
		component->Update();
	}
}
