#pragma once
#include "Transform.h"
#include <vector>
#include <iostream>

class Actor
{
public:
	class Scene* myScene;

	Actor(class Scene* myScene);
	virtual ~Actor();

	Transform transform {};
	virtual void Update();
	void InternalUpdate();
	virtual void Render();

	Vector2 screenPosition;
	std::string tag = "Untagged";

	std::vector<class Component*> components;

	void AddComponent(class Component* newComponent);

	bool ToDelete();
	void ToDelete(bool b);

	void Tag(std::string tag);

	virtual void OnCollisionEnter(class Collider* other);
	virtual void OnCollisionStay(class Collider* other);

protected:
	bool toDelete = false;
};

