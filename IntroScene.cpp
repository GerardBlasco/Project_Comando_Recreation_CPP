#include "IntroScene.h"
#include "Component.h"
#include "Sprite.h"
#include "Actor.h"
#include "Background.h"
#include "Player.h"
#include "Camera.h"
#include "Enemy.h"
#include "SDL3/SDL.h"
#include "InputSystem.h"
#include "Pickeable.h"
#include "HUD.h"

IntroScene::IntroScene(GraphicsInterface* GI):Scene(GI)
{
	GI->LoadImage("icon_granade.png");
	GI->LoadImage("first_zone_map.png");
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

	Background* map = new Background(this, "first_zone_map.png", 640, 3120);
	map->AlignToBottom();
	actors.push_back(map);

	HUD* hud = new HUD(this);
	actors.push_back(hud);

	Player* player = new Player(this);
	actors.push_back(player);

	mainCamera = new Camera(this, player);
	mainCamera->HorizontalMovement(false);
	actors.push_back(mainCamera);

	Enemy* enemy = new Enemy(this, player);

	actors.push_back(enemy);

	Pickeable* pickeable = new Pickeable(this);

	actors.push_back(pickeable);

	//Sprite* sprite = new Sprite(this, "UFO.png", 100);
	//actors.push_back(sprite);
}
