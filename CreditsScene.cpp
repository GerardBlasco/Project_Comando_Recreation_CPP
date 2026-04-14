#include "CreditsScene.h"
#include "GraphicsInterface.h"
#include "IntroScene.h"
#include "Game.h"
#include "InputSystem.h"
#include "MenuScene.h"

CreditsScene::CreditsScene(GraphicsInterface* GI) : Scene(GI)
{
	selectedOption = 0;
	
	InputSystem::CreateMap("GoBackToMainMenu");
	InputSystem::Map("GoBackToMainMenu")->AddBinding(SDLK_F);
	InputSystem::Map("GoBackToMainMenu")->AddListener(this, &CreditsScene::HandleInput, InputEvent::Triggered);
}

CreditsScene::~CreditsScene()
{
	InputSystem::DeleteMap("GoBackToMainMenu");
}


void CreditsScene::Update()
{
}

void CreditsScene::Render()
{
	GI->DrawText("Juego basado en el Commando Commodore 64", 100, 120);
	GI->DrawText("Creadores: Gerard Blasco e Iris Frades", 100, 160);
	GI->DrawText("Professor: Francisco Arias", 100, 200);

	GI->DrawText((selectedOption == 0 ? "> Salir al menu principal" : "> Salir al menu principal"), 100, 240);
}

void CreditsScene::HandleInput()
{
	
	Game::ChangeScene(new MenuScene(GI));	
	
}
