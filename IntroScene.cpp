#include "IntroScene.h"
#include "Component.h"
#include "Sprite.h"
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "SDL3/SDL.h"
#include "InputSystem.h"
#include "Pickeable.h"

IntroScene::IntroScene(GraphicsInterface* GI):Scene(GI)
{
	GI->LoadImage("player.png");
	GI->LoadImage("bullet.png");
	GI->LoadImage("granade.png");
	GI->LoadImage("enemy.png");
	GI->LoadImage("bullet_explosion.png");
	GI->LoadImage("explosion.png");
	GI->LoadImage("granade_stack.png");

	InputSystem::CreateMap("Horizontal");
	InputSystem::CreateMap("Vertical");
	InputSystem::CreateMap("PrimaryAttack");
	InputSystem::CreateMap("SecondaryAttack");

	InputSystem::Map("Horizontal")->AddBinding(SDLK_D);
	InputSystem::Map("Horizontal")->AddBinding(SDLK_A, true);

	InputSystem::Map("Vertical")->AddBinding(SDLK_W, true);
	InputSystem::Map("Vertical")->AddBinding(SDLK_S);

	InputSystem::Map("PrimaryAttack")->AddBinding(SDL_BUTTON_LEFT);
	InputSystem::Map("SecondaryAttack")->AddBinding(SDL_BUTTON_RIGHT);

	Player* player = new Player(this);

	//Sprite* sprite = new Sprite(player, "UFO.png", 100);

	actors.push_back(player);

	Enemy* enemy = new Enemy(this, player);

	actors.push_back(enemy);

	Pickeable* pickeable = new Pickeable(this);

	actors.push_back(pickeable);

	//Sprite* sprite = new Sprite(this, "UFO.png", 100);
	//actors.push_back(sprite);
}
