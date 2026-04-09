#include "IntroScene.h"
#include "Component.h"
#include "Sprite.h"
#include "Actor.h"
#include "Player.h"
#include "SDL3/SDL.h"
#include "InputSystem.h"

IntroScene::IntroScene(GraphicsInterface* GI):Scene(GI)
{
	GI->LoadImage("UFO.png");

	InputSystem::CreateMap("Horizontal");
	InputSystem::CreateMap("Vertical");

	InputSystem::Map("Horizontal")->AddBinding(SDLK_D);
	InputSystem::Map("Horizontal")->AddBinding(SDLK_A, true);

	InputSystem::Map("Vertical")->AddBinding(SDLK_W, true);
	InputSystem::Map("Vertical")->AddBinding(SDLK_S);

	Player* player = new Player(this);

	//Sprite* sprite = new Sprite(player, "UFO.png", 100);

	actors.push_back(player);

	//Sprite* sprite = new Sprite(this, "UFO.png", 100);
	//actors.push_back(sprite);
}
