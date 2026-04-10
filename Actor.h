#pragma once
#include "Transform.h"
#include <vector>

class Actor
{
public:
	class Scene* myScene;

	Actor(class Scene* myScene);
	Transform transform {};
	virtual void Update();
	virtual void Render();

	std::vector<class Component*> components;

	void AddComponent(class Component* newComponent);

	bool ToDelete();

protected:
	bool toDelete = false;
	
};

