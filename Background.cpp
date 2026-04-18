#include "Background.h"
#include "Parameters.h"
#include "Sprite.h"
#include "Scene.h"
#include "RectangleCollider.h"

Background::Background(Scene* myScene, std::string imageName, float width, float height):Actor(myScene)
{
	transform.position = Vector2(Parameters::width * 0.5f, Parameters::height * 0.5f);
	AddComponent(new Sprite(this, imageName, width, height));

	RectangleCollider* bottomDeadZone = new RectangleCollider(this, width, 300, Color(255, 0, 0, 255));
	bottomDeadZone->IsTrigger(true);
	bottomDeadZone->AddOffset(Vector2(0, (height - 300) * 0.5f));
	AddComponent(bottomDeadZone);

	RectangleCollider* topDeadZone = new RectangleCollider(this, width, 300, Color(255, 0, 0, 255));
	topDeadZone->IsTrigger(true);
	topDeadZone->AddOffset(Vector2(0, (-height + 300) * 0.5f));
	AddComponent(topDeadZone);

	this->width = width;
	this->height = height;
}

void Background::AlignToBottom()
{
	transform.position.y = Parameters::height - (height * 0.5f);
}

void Background::OnCollisionEnter(class Collider* other) 
{
	if (other->Parent()->tag == "Player") {
		myScene->mainCamera->VerticalMovement(false);
	}
}

void Background::OnCollisionExit(class Collider* other)
{
	if (other->Parent()->tag == "Player") {
		myScene->mainCamera->VerticalMovement(true);
	}
}
