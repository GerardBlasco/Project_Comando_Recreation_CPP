#pragma once
#include "Actor.h"
class Background : public Actor
{
public:
	float width, height;
	
	Background(Scene* myScene, std::string imageName, float width, float height);
	void AlignToBottom();

	virtual void OnCollisionEnter(class Collider* other);
};

