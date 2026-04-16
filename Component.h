#pragma once
class Component
{
public:
	Component(class Actor* parent);
	virtual ~Component();

	virtual void Update();
	virtual void Render();

	Actor* Parent();

protected:
	class Actor* parent;

};

