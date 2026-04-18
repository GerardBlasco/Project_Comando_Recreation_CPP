#include "Text.h"
#include "Scene.h"

Text::Text(Scene* myScene, std::string content, Vector2 position):Actor(myScene)
{
	this->content = content;
	this->position = position;
}

void Text::Render()
{
	myScene->GI->DrawText(content, position.x, position.y);
}

void Text::SetContent(std::string newContent)
{
	content = newContent;
}
