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
#include "WorldBarrier.h"

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

	//El push back es para que se muestre por pantalla todo aquello que tu indiques
	//FONDO DEL MAPA
	Background* map = new Background(this, "first_zone_map.png", 640, 3120);
	map->AlignToBottom();
	actors.push_back(map);

	//PLAYER
	Player* player = new Player(this);

	//HUD
	HUD* hud = new HUD(this, player);
	actors.push_back(hud);

	actors.push_back(player);

	//COLLIDERS DEL MUNDO
	WorldBarrier* leftBarrier = new WorldBarrier(this, map, player, Vector2(50, 200), Vector2(640, 3120), false);
	leftBarrier->AlignLeft();
	actors.push_back(leftBarrier);

	WorldBarrier* rightBarrier = new WorldBarrier(this, map, player, Vector2(50, 200), Vector2(640, 3120), false);
	rightBarrier->AlignRight();
	actors.push_back(rightBarrier);

	WorldBarrier* bottomBarrier = new WorldBarrier(this, map, player, Vector2(640, 50), Vector2(640, 3120));
	bottomBarrier->AlignBottom();
	actors.push_back(bottomBarrier);

	WorldBarrier* topBarrier = new WorldBarrier(this, map, player, Vector2(640, 50), Vector2(640, 3120));
	topBarrier->AlignTop();
	actors.push_back(topBarrier);

	//CAMARA
	mainCamera = new Camera(this, player);
	mainCamera->HorizontalMovement(false);
	actors.push_back(mainCamera);

	//ENEMIGO
	Enemy* enemy = new Enemy(this, player);
	actors.push_back(enemy);

	//OBJETO PICKEABLE
	Pickeable* pickeable = new Pickeable(this, player);
	actors.push_back(pickeable);

}


