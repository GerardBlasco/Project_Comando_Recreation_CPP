#pragma once
#include "Actor.h"
class Camera : public Actor
{
public:
	Camera(Scene* myScene);
	Camera(Scene* myScene, Actor* target);

	void SetFollowTarget(Actor* target);

	virtual void Update();

	static Vector2 ScreenToWorld(Vector2 screenPos, Camera* camera);
	static Vector2 GetScreenCenter();

private:
	Actor* followTarget;
};

