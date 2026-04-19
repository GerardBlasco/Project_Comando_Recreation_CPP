#include "Game.h"
#include "GraphicsInterface.h"
#include "InputSystem.h"
#include "SDL3/SDL.h"
#include "Parameters.h"
#include "IntroScene.h"
#include "MenuScene.h"
#include <Windows.h>
#include "AudioManager.h"

Game* Game::instance = 0;
float Game::deltaTime = 0.0f;
int Game::globalHighScore = 0; //guardamos la HighScore aqui para que no se borre en cuanto cambiemos de escenas

void Game::Create()
{
	if (!instance)
		instance = new Game();
}

void Game::Destroy()
{
	if (instance)
		delete instance;
}

void Game::ChangeScene(Scene* newScene)
{
	if (instance->currentScene) {
		delete instance->currentScene;
	}

	instance->currentScene = newScene;

	InputSystem::ResetInputs();
}

float Game::DeltaTime()
{
	
	return deltaTime;
}

void Game::Play()
{
	if (instance)
		instance->Loop();
}

Game::Game()
{
	AudioManager::instance().init(); //Inicializamops el audioManager

	GI = new GraphicsInterface();
	currentScene = new MenuScene(GI);

	//Añadimos sonido de fondo
	AudioManager::instance().playMusic("bg_sound.mp3"); //Instanciamos la musica
	AudioManager::instance().setMusicVolume(20);//seteamos un volumen

}

Game::~Game()
{
	//AudioManager::instance().close();//Cerramos la instancia al audioManager
	delete GI;
}

void Game::Update()
{
	InputSystem::Update();

	if (InputSystem::EventQuit()) {
		game_end = true;
	}


	currentScene->Update();
}

void Game::Render()
{
	currentScene->Render();
}

void Game::Loop()
{
	//bool game_end = false;
	float desiredDeltaTime = 1.0f / Parameters::desired_FPS;
	unsigned int lastTicks = SDL_GetTicks();
	while (!game_end)
	{
		unsigned int currentTicks = SDL_GetTicks();
		//game_end = GI->MustWindowClose();
		deltaTime = (currentTicks - lastTicks) / 1000.f;
		lastTicks = currentTicks;

		Update();

		GI->ClearFrame();
		Render();
		GI->DrawFrame();

		float frameTime = (SDL_GetTicks() - currentTicks) / 1000.f;

		if (frameTime < desiredDeltaTime) {
			float delay = desiredDeltaTime - frameTime;
			SDL_Delay(delay * 1000.f);
		}
		//Sleep(int(abs(desiredDeltaTime - DeltaTime) / 1000));
	}
}
