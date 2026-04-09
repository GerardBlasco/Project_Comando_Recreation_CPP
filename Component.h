#pragma once
class Component
{
public:
	Component(class Actor* parent);

	virtual void Update();
	virtual void Render();

protected:
	class Actor* parent;

};

