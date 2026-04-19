#pragma once
#include <vector>
#include <map>
#include "GraphicsInterface.h"
#include "InputSystem.h"
#include "Camera.h"
#include "WorldObstacle.h"
#include "MapData.h"

class Scene
{
protected:
	std::vector<class Actor*> actorsToAdd;
	std::vector<class Actor*> actors;
	std::vector<class RectangleCollider*> existingColliders;
	std::vector<class RectangleCollider*> collidersToDelete;

	MapData currentData;
	class Background* background;

	void GenerateObstacles();

public:
	GraphicsInterface* GI;
	Camera* mainCamera;

	bool waitingSceneChange = false;
	Scene* nextScene;

	Scene(GraphicsInterface* GI);
	virtual ~Scene();
	virtual void Update();
	virtual void Render();

	void LoadActor(class Actor* actor);
	void LoadCollider(class RectangleCollider* collider);
	void RemoveCollider(class RectangleCollider* collider);

	virtual void HandleInput();
	virtual void ChangeToScene();

	bool ColliderStillExists(class RectangleCollider* collider);

	std::vector<class Actor*> GetAllActors();

	void CheckCollisions();
};

