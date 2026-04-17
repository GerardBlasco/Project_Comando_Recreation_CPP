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

void Camera::VerticalMovement(bool verticalMovement)
{
	this->verticalMovement = verticalMovement;
}

void Camera::HorizontalMovement(bool horizontalMovement)
{
	this->horizontalMovement = horizontalMovement;
}

void Camera::Update()
{
	if (!followTarget) {
		transform.position = GetScreenCenter();
		return;
	}

	if (horizontalMovement) {
		transform.position.x = followTarget->transform.position.x;
	}
	else {
		transform.position.x = GetScreenCenter().x;
	}
	
	if (verticalMovement) {
		transform.position.y = followTarget->transform.position.y;
	}
	else {
		transform.position.y = 0;
	}
}

Vector2 Camera::ScreenToWorld(Vector2 screenPos, Camera* camera)
{
	return screenPos + camera->transform.position - GetScreenCenter();
}

Vector2 Camera::GetScreenCenter()
{
	return Vector2(Parameters::width * 0.5f, Parameters::height * 0.5f);
}
