#include "Component.h"
#include "Actor.h"
#include <iostream>

Component::Component(Actor* parent)
{
	this->parent = parent;
}

Component::~Component()
{
}

void Component::Update()
{

}

void Component::Render()
{

}

Actor* Component::Parent()
{
	return parent;
}

void Component::ToDelete(bool b)
{
	toDelete = b;
}

bool Component::ToDelete()
{
	return toDelete;
}
