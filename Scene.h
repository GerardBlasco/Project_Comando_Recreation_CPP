#pragma once
#include <vector>
#include "GraphicsInterface.h"
#include "InputSystem.h"
#include "Camera.h"

class Scene
{
protected:
	std::vector<class Actor*> actorsToAdd;
	std::vector<class Actor*> actors;
	std::vector<class RectangleCollider*> existingColliders;

public:
	GraphicsInterface* GI;
	Camera* mainCamera;

	Scene(GraphicsInterface* GI);
	virtual ~Scene();
	virtual void Update();
	virtual void Render();

	void LoadActor(class Actor* actor);
	void LoadCollider(class RectangleCollider* collider);
	void RemoveCollider(class RectangleCollider* collider);

	virtual void HandleInput();
	virtual void ChangeToScene();

	std::vector<class Actor*> GetAllActors();

	void CheckCollisions();
};

