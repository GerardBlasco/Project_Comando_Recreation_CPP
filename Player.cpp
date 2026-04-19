#include "Player.h"
#include "Game.h"
#include "Weapon.h"
#include "Bullet.h"
#include "Granade.h"
#include "Sprite.h"
#include "RectangleCollider.h"
#include "Parameters.h"
#include "Animation.h"
#include "InputSystem.h"
#include "Scene.h"
#include "Color.h"
#include "Animator.h"
#include "DefeatScene.h"
#include "PauseMenu.h"
#include "IntroScene.h"
#include "AudioManager.h"

Player::Player(Scene* myScene):Actor(myScene)
{
	AudioManager::instance().init(); //Inicializamos el audioManager

	health = 5; //vida inicial
	granadesLeft = 5;//granadas iniciales

	AddComponent(new RectangleCollider(this, 40, 40, Color(0, 0, 255, 255)));

	animator = new Animator(this);
	AddComponent(animator);

	std::map<int, std::string> directions = 
	{ 
		{0, "Right"}, 
		{1, "DownRight"}, 
		{2, "Down"}, 
		{3, "DownLeft"}, 
		{4, "Left"}, 
		{5, "UpLeft"}, 
		{6, "Up"}, 
		{7, "UpRight"} 
	};

	std::vector<std::string> sheetOrder = 
	{ 
		"Down", 
		"Up", 
		"Left", 
		"Right", 
		"DownLeft", 
		"DownRight", 
		"UpLeft", 
		"UpRight" 
	};

	animator->GenerateAnimationsRange("player.png", "Walk", sheetOrder, 0, 0, 6, 8, 4, 40.f, 40.f);
	animator->GenerateAnimationsRange("player.png", "Idle", sheetOrder, 96, 0, 6, 8, 2, 40.f, 40.f, 0.5f);
	animator->LoadDirectionsOrder(directions);

	tag = "Player";

	transform.position = Vector2(Parameters::width * 0.5f, Parameters::height * 0.5f);

	// ESTO SON INPUTS
	InputSystem::Map("Horizontal")->AddListener(this, &Player::MoveHorizontal);
	InputSystem::Map("Vertical")->AddListener(this, &Player::MoveVertical);
	InputSystem::Map("PrimaryAttack")->AddListener(this, &Player::Shoot, InputEvent::Triggered);
	InputSystem::Map("SecondaryAttack")->AddListener(this, &Player::ShootAlternative, InputEvent::Triggered);
}

Player::~Player()
{
	//AudioManager::instance().close(); //Cerramos la instancia al audioManager
}

//METODOS PARA LA VIDA
void Player::LoseHealth(const int quantity)
{
	health = health - quantity;
}

void Player::OnCollisionEnter(Collider* other)
{
	if (other->Parent()->tag == "EnemyAttack") //Los ataques del enemigo
	{
<<<<<<< HEAD
		//Sonido cuando hacen daño al player
		AudioManager::instance().playSFX("hurted_sound.mp3");
		AudioManager::instance().setSFXVolume(10);

		LoseHealth(1); //Llamamos a la funcion LoseHealth()
		if (!isInvulnerable) {
			LoseHealth(1); //Llamamos a la funcion LoseHealth()

		//Si la vida es menor o igual a 0
		if (health <= 0) {
			//Sonido de derrota
			AudioManager::instance().playSFX("lose_sound.mp3");
			AudioManager::instance().setSFXVolume(30);

			Game::ChangeScene(new DefeatScene(myScene->GI)); //cambiamos a la escena de derrota
			isInvulnerable = true;
			time = 0.f;
			blinkTime = 0.f;
			visible = true;
=======
		//Llamamos a la funcion LoseHealth()
		if (!isInvulnerable) {
			//Sonido cuando hacen daño al player
			AudioManager::instance().playSFX("hurted_sound.mp3");
			AudioManager::instance().setSFXVolume(10);

			LoseHealth(1); //Llamamos a la funcion LoseHealth()
>>>>>>> e2ce48c5058a7f4c55e5b9ff70eb93312d127a75

			//Si la vida es menor o igual a 0
			if (health <= 0) {
				//Sonido de derrota
				AudioManager::instance().playSFX("lose_sound.mp3");
				AudioManager::instance().setSFXVolume(30);

				//Game::ChangeScene(new DefeatScene(myScene->GI)); //cambiamos a la escena de derrota
				dead = true;
				isInvulnerable = true;
				time = 0.f;
				blinkTime = 0.f;
				visible = true;
			}
		}
	}
}

int Player::GetHealth()
{
	return health;
}

//METODOS PARA GRANADAS
void Player::SetGranadesQuantity(int quantity)
{
	granadesLeft = granadesLeft + quantity;
}

int Player::GetGranades()
{
	return granadesLeft;
}

void Player::LoseGranade()
{
	granadesLeft -= 1;

	//que el texto se quede a 0 si no tiene mas
	if (granadesLeft <= 0) {
		granadesLeft = 0;
	}
}

//METODOS PARA PUNTUACION
void Player::AddScore(int amount)
{
	score += amount;
}

int Player::GetScore()
{
	return score;
}
//----------------------------//

void Player::Update() 
{

	bool isMoving = InputSystem::Map("Horizontal")->performed || InputSystem::Map("Vertical")->performed;

	Vector2 mousePosition(InputSystem::DeltaX(), InputSystem::DeltaY());

	Vector2 mouseWorldPosition = Camera::ScreenToWorld(mousePosition, myScene->mainCamera);
	Vector2 mouseDirection = mouseWorldPosition - transform.position;

	animator->SetCurrentIndex(Vector2::DirectionIndex(mouseDirection, 8));

	std::string animationName;

	if (isMoving) {
		animationName = "Walk" + animator->GetDirection(animator->GetCurrentIndex());
	}
	else {
		animationName = "Idle" + animator->GetDirection(animator->GetCurrentIndex());
	}

	if (animator->GetCurrentAnimationName() != animationName) {
		animator->SetCurrentAnimationName(animationName);
		animator->PlayAnimation(animationName);
	}

	if (dead) {
		//Game::ChangeScene(new DefeatScene(myScene->GI)); //cambiamos a la escena de derrota
		myScene->waitingSceneChange = true;
		myScene->nextScene = new DefeatScene(myScene->GI);
	}

	if (isInvulnerable) {
		time += Game::DeltaTime();
		blinkTime += Game::DeltaTime();

		if (blinkTime >= blinkDuration) {
			blinkTime = 0.f;
			visible = !visible;

			for (auto& pair : animator->Animations())
			{
				if (visible) {
					pair.second->Show();
				}
				else {
					pair.second->Hide();
				}
			}
		}

		if (time >= duration) {
			isInvulnerable = false;
			visible = true;

			for (auto& pair : animator->Animations())
			{
				pair.second->Show();
			}
		}
	}
}

//METODOS DE MOVIMIENTO DEL PERSONAJE
void Player::MoveHorizontal()
{
	transform.position.x += InputSystem::Map("Horizontal")->ReadFloat() * 200.f * Game::DeltaTime();
}

void Player::MoveVertical()
{
	transform.position.y += InputSystem::Map("Vertical")->ReadFloat() * 200.f * Game::DeltaTime();
}


//METODOS DE DISPARO DEL PERSONAJE
void Player::Shoot()
{
	//Añadimos sonido al disparo
	AudioManager::instance().playSFX("shoot_sound.mp3");
	AudioManager::instance().setSFXVolume(60);

	Vector2 mouseWorldPosition = Camera::ScreenToWorld(Vector2(InputSystem::DeltaX(), InputSystem::DeltaY()), myScene->mainCamera);

	Weapon* bullet = new Bullet(myScene, transform.position, mouseWorldPosition);
	myScene->LoadActor(bullet);
}

void Player::ShootAlternative()
{

	if (granadesLeft <= 0) return; //si no tiene granadas, salimos del metodo

	// Añadimos sonido al disparo granada
	AudioManager::instance().playSFX("granade_shoot.mp3");
	AudioManager::instance().setSFXVolume(60);

	Vector2 mouseWorldPosition = Camera::ScreenToWorld(Vector2(InputSystem::DeltaX(), InputSystem::DeltaY()), myScene->mainCamera);

	Weapon* granade = new Granade(myScene, transform.position, mouseWorldPosition);
	myScene->LoadActor(granade);

	LoseGranade();//perdemos 1 granada
}
