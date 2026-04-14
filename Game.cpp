#include "Game.h"
#include "GraphicsInterface.h"
#include "InputSystem.h"
#include "SDL3/SDL.h"
#include "Parameters.h"
#include "IntroScene.h"
#include <Windows.h>
#include "MenuScene.h"

Game* Game::instance = 0;
float Game::deltaTime = 0.0f;

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
	GI = new GraphicsInterface();
	currentScene = new MenuScene(GI);

	InputSystem::CreateMap("CloseGame");
	InputSystem::Map("CloseGame")->AddBinding(SDLK_ESCAPE);
}

Game::~Game()
{
	delete GI;
}

void Game::Update()
{
	InputSystem::Update();

	if (InputSystem::Map("CloseGame")->triggered || InputSystem::EventQuit()) {
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
