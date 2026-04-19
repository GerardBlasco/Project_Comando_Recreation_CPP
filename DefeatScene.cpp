#include "DefeatScene.h"
#include "Scene.h"
#include "Text.h"
#include "MenuScene.h"
#include "Game.h"
#include "IntroScene.h"

DefeatScene::DefeatScene(GraphicsInterface* GI): Scene(GI)
{
	InputSystem::CreateMap("DefeatSceneInputs");
	InputSystem::CreateMap("ChangeToSelectedOption");

	//De derecha a izquierda
	InputSystem::Map("DefeatSceneInputs")->AddBinding(SDLK_A);
	InputSystem::Map("DefeatSceneInputs")->AddBinding(SDLK_D, true);

	//Aceptar seleccion
	InputSystem::Map("ChangeToSelectedOption")->AddBinding(SDLK_RETURN);

	InputSystem::Map("DefeatSceneInputs")->AddListener(this, &DefeatScene::HandleInput, InputEvent::Triggered);
	InputSystem::Map("ChangeToSelectedOption")->AddListener(this, &DefeatScene::ChangeToScene, InputEvent::Triggered);

	//Asignamos cada opcion a cada variable
	menuOption1 = new Text(this, "> Try again", Vector2(200, 500));
	menuOption2 = new Text(this, "Return to lobby", Vector2(500, 500));

	//Los escribimos por pantalla
	actors.push_back(new Text(this, "You lose ", Vector2(400, 120)));
	actors.push_back(menuOption1);
	actors.push_back(menuOption2);

}
void DefeatScene::HandleInput()
{
	float value = InputSystem::Map("DefeatSceneInputs")->ReadFloat(); //Lee el float de ese input -1 o 1

	//Segun el valor...
	if (value > 0)
	{
		selectedOption++;
	}
	else if (value < 0)
	{
		selectedOption--;
	}

	if (selectedOption < 0) {
		selectedOption = 1;
	}

	if (selectedOption > 1) {
		selectedOption = 0;
	}

	//Opciones que puede escojer el usuario
	menuOption1->SetContent(selectedOption == 0 ? "> Try again" : "Try again");
	menuOption2->SetContent(selectedOption == 1 ? "> Return to lobby" : "Return to lobby");
}

void DefeatScene::ChangeToScene()
{
	switch (selectedOption)
	{
	case 0:
		Game::ChangeScene(new IntroScene(GI)); //Cambio de escena a introScene, al juego de nuevo
		break;
	case 1:
		Game::ChangeScene(new MenuScene(GI)); //Cambio de escena al menuScene
	default:
		break;
	}
}

