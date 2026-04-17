#include "Camera.h"
#include "Parameters.h"
#include "Scene.h"

Camera::Camera(Scene* myScene):Actor(myScene)
{

}

Camera::Camera(Scene* myScene, Actor* target):Actor(myScene)
{
	followTarget = target;
}

void Camera::SetFollowTarget(Actor* target)
{
	followTarget = target;
}

void Camera::Update()
{
	if (!followTarget) {
		transform.position = GetScreenCenter();
		return;
	}

	transform.position = followTarget->transform.position;
}

Vector2 Camera::ScreenToWorld(Vector2 screenPos, Camera* camera)
{
	return screenPos + camera->transform.position - GetScreenCenter();
}

Vector2 Camera::GetScreenCenter()
{
	return Vector2(Parameters::width * 0.5f, Parameters::height * 0.5f);
}
