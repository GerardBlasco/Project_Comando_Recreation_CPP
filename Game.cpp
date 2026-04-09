#include "Game.h"
#include "GraphicsInterface.h"
#include "InputSystem.h"
#include "SDL3/SDL.h"
#include "Parameters.h"
#include "IntroScene.h"
#include <Windows.h>

Game* Game::instance = 0;
float Game::DeltaTime = 0.0f;

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

void Game::Play()
{
	if (instance)
		instance->Loop();
}

Game::Game()
{
	GI = new GraphicsInterface();
	currentScene = new IntroScene(GI);

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
	unsigned int millis = SDL_GetTicks();
	float desired_deltatime = 1.0f / Parameters::desired_FPS;
	while (!game_end)
	{
		//game_end = GI->MustWindowClose();
		Update();

		GI->ClearFrame();
		Render();
		GI->DrawFrame();

		DeltaTime = (SDL_GetTicks() - millis) / 1000.f;

		Sleep(int(abs(desired_deltatime - DeltaTime) / 1000));
	}
}
