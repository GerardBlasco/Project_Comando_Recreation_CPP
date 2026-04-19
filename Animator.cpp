#include "Animator.h"
#include "Animation.h"
#include "Actor.h"
#include "Scene.h"
#include "SDL3_image/SDL_image.h"

Animator::Animator(Actor* parent):Component(parent)
{

}

Animator::~Animator()
{
	for (auto& pair : animations) {
		delete pair.second;
	}
	animations.clear();
}

void Animator::LoadAnimation(std::string name, Animation* animation)
{
	animation->Stop();
	//std::cout << "Created animation: " << name << std::endl;
	animations[name] = animation;
}

void Animator::PlayAnimation(std::string name)
{
	for (auto& pair : animations) {
		pair.second->Stop();
	}

	currentAnimation = animations[name];
	currentAnimation->Play();
}

void Animator::SetCurrentIndex(int index)
{
	currentIndex = index;
}

int Animator::GetCurrentIndex()
{
	return currentIndex;
}

void Animator::Render()
{
	if (!currentAnimation) return;
	currentAnimation->Render();
}

std::map<std::string, class Animation*> Animator::Animations()
{
	return animations;
}

void Animator::LoadDirectionsOrder(std::map<int, std::string> orderedDirections)
{
	for (auto& pair : orderedDirections) {
		//std::cout << "Key: " << pair.first << " | Name: " << pair.second << std::endl;
		directions[pair.first] = pair.second;
	}
}

std::string Animator::GetDirection(int id)
{
	return directions[id];
}

std::string Animator::GetCurrentAnimationName()
{
	return currentAnimationName;
}

void Animator::SetCurrentAnimationName(std::string name)
{
	currentAnimationName = name;
}

Animation* Animator::CreateAnimation(std::string sheetName, int x, int y, int columns, int rows, int numFrames, float width, float height, float frameRate)
{
	Animation* animation = new Animation(parent, sheetName, columns, rows, width, height);
	animation->LoadFrames(x, y, numFrames);
	animation->SetFrameRate(frameRate);
	return animation;
}

void Animator::GenerateAnimationsRange(std::string sheetName, std::string state, std::vector<std::string> names, int x, int y, int columns, int rows, int numFrames, float width, float height, float frameRate)
{
	float frameWidth;
	float frameHeight;
	SDL_GetTextureSize(parent->myScene->GI->GetTexture(sheetName), &frameWidth, &frameHeight);

	frameWidth /= columns;
	frameHeight /= rows;

	for (int i = 0; i < names.size(); i++) {
		LoadAnimation(state + names[i], CreateAnimation(sheetName, x, y + (frameHeight * i), columns, rows, numFrames, width, height, frameRate));
	}
}
