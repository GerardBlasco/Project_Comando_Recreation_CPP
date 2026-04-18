#include "MenuScene.h"
#include "Text.h"
#include "InputSystem.h"
#include "IntroScene.h"
#include "HelpScene.h"
#include "CreditsScene.h"
#include "Game.h"

MenuScene::MenuScene(GraphicsInterface* GI) : Scene(GI)//, selectedOption(0)
{
	//Mapping de las teclas
	InputSystem::CreateMap("MoveOptionsMenu");
	InputSystem::CreateMap("EnterToOptionSelected");

	InputSystem::Map("MoveOptionsMenu")->AddBinding(SDLK_UP, true);
	InputSystem::Map("MoveOptionsMenu")->AddBinding(SDLK_DOWN);

	InputSystem::Map("EnterToOptionSelected")->AddBinding(SDLK_T);

	InputSystem::Map("MoveOptionsMenu")->AddListener(this, &MenuScene::HandleInput, InputEvent::Triggered);
	InputSystem::Map("EnterToOptionSelected")->AddListener(this, &MenuScene::ChangeToScene, InputEvent::Triggered);

	menuOption1 = new Text(this, "> Jugar", Vector2(100, 120));
	menuOption2 = new Text(this, "Ayuda", Vector2(100, 150));
	menuOption3 = new Text(this, "Creditos", Vector2(100, 180));
	menuOption4 = new Text(this, "Salir", Vector2(100, 210));

	actors.push_back(new Text(this, "Menu principal", Vector2(100, 50)));
	actors.push_back(menuOption1);
	actors.push_back(menuOption2);
	actors.push_back(menuOption3);
	actors.push_back(menuOption4);
}

MenuScene::~MenuScene()
{
	//InputSystem::DeleteMap("MoveOptionsMenu");
	//InputSystem::DeleteMap("EnterToOptionSelected");
}

void MenuScene::HandleInput()
{
	float value = InputSystem::Map("MoveOptionsMenu")->ReadFloat();

	if (value > 0)
	{
		selectedOption++;
	}
	else if (value < 0)
	{
		selectedOption--;
	}

	if (selectedOption < 0) {
		selectedOption = 3;
	}

	if (selectedOption > 3) {
		selectedOption = 0;
	}

	menuOption1->SetContent(selectedOption == 0 ? "> Jugar" : "Jugar");
	menuOption2->SetContent(selectedOption == 1 ? "> Ayuda" : "Ayuda");
	menuOption3->SetContent(selectedOption == 2 ? "> Creditos" : "Creditos");
	menuOption4->SetContent(selectedOption == 3 ? "> Salir" : "Salir");
}

void MenuScene::ChangeToScene()
{
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
	case 3:
		//Game::QuitGame();
		break;
	}
}
