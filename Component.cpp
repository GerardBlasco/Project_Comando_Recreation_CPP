#include "Component.h"
#include "Actor.h"

Component::Component(Actor* parent)
{
	this->parent = parent;
	this->parent->AddComponent(this);
}

void Component::Update()
{

}

void Component::Render()
{

}
