#include "MenuScene.h"
#include "Game.h"
#include "IntroScene.h"
#include "GraphicsInterface.h"
#include "InputSystem.h"
#include "CreditsScene.h"
#include "HelpScene.h"

MenuScene::MenuScene(GraphicsInterface* GI) : Scene (GI), selectedOption(0)
{
	InputSystem::CreateMap("MoveOptionsMenu");
	InputSystem::CreateMap("EnterToOptionSelected");

	InputSystem::Map("MoveOptionsMenu")->AddBinding(SDLK_UP, true);
	InputSystem::Map("MoveOptionsMenu")->AddBinding(SDLK_DOWN);
	
	InputSystem::Map("EnterToOptionSelected")->AddBinding(SDLK_T); 

	InputSystem::Map("MoveOptionsMenu")->AddListener(this, &MenuScene::HandleInput, InputEvent::Triggered);
	InputSystem::Map("EnterToOptionSelected")->AddListener(this, &MenuScene::ChangeToScene, InputEvent::Triggered);

}

MenuScene::~MenuScene()
{
	InputSystem::DeleteMap("MoveOptionsMenu");
	InputSystem::DeleteMap("EnterToOptionSelected");
}

void MenuScene::Update()
{

}

void MenuScene::Render()
{
	GI->DrawText("Menu principal", 100, 50);

	GI->DrawText((selectedOption == 0 ? "> Jugar" : "Jugar"), 100, 120);
	GI->DrawText((selectedOption == 1 ? "> Ayuda" : "Ayuda"), 100, 150);
	GI->DrawText((selectedOption == 2 ? "> Creditos" : "Creditos"), 100, 180);
	GI->DrawText((selectedOption == 3 ? "> Salir" : "Salir"), 100, 210);

}

void MenuScene::HandleInput()
{
	float value = InputSystem::Map("MoveOptionsMenu")->ReadFloat();

	if (value > 0) 
	{
		selectedOption++;
	}else if (value < 0)
	{
		selectedOption--;
	}
	
	if (selectedOption < 0) {
		selectedOption = 3;
	}

	if (selectedOption > 3) {
		selectedOption = 0;
	}
	std::cout << "HANDLE ";

}

void MenuScene::ChangeToScene()
{
	std::cout << "CHANGE ";

		switch (selectedOption)
		{
		case 0:
			Game::ChangeScene(new IntroScene(GI));
			break;
		case 1:
			Game::ChangeScene(new HelpScene(GI));
			break;
		case 2:
			Game::ChangeScene(new CreditsScene(GI));
			
			break;
		}	
}

