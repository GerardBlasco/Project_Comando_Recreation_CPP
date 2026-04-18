#pragma once
#include "Vector2.h"
class Component
{
public:
	Component(class Actor* parent);
	virtual ~Component();

	virtual void Update();
	virtual void Render();

	void ToDelete(bool b);
	bool ToDelete();

	Actor* Parent();

protected:
	class Actor* parent;

private:
	bool toDelete = false;

};

