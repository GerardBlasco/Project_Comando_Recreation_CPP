#include "VictoryScene.h"
#include "Scene.h"
#include "Text.h"
#include "MenuScene.h"
#include "Game.h"
#include "IntroScene.h"

VictoryScene::VictoryScene(GraphicsInterface* GI): Scene(GI)
{
	InputSystem::CreateMap("VictorySceneInputs");
	InputSystem::CreateMap("ChangeToSelectedOptions");

	//De derecha a izquierda
	InputSystem::Map("VictorySceneInputs")->AddBinding(SDLK_A);
	InputSystem::Map("VictorySceneInputs")->AddBinding(SDLK_D, true);

	//Aceptar seleccion
	InputSystem::Map("ChangeToSelectedOptions")->AddBinding(SDLK_RETURN);

	InputSystem::Map("VictorySceneInputs")->AddListener(this, &VictoryScene::Inputs, InputEvent::Triggered);
	InputSystem::Map("ChangeToSelectedOptions")->AddListener(this, &VictoryScene::ChangeToScenes, InputEvent::Triggered);

	//Asignamos cada opcion a cada variable
	menuOption1 = new Text(this, "> Play again", Vector2(200, 500));
	menuOption2 = new Text(this, "Return to lobby", Vector2(500, 500));

	//Los escribimos por pantalla
	actors.push_back(new Text(this, "You win ", Vector2(400, 120)));
	actors.push_back(menuOption1);
	actors.push_back(menuOption2);
}

void VictoryScene::Inputs()
{
	float value = InputSystem::Map("VictorySceneInputs")->ReadFloat(); //Lee el float de ese input -1 o 1

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
	menuOption1->SetContent(selectedOption == 0 ? "> Play again" : "Play again");
	menuOption2->SetContent(selectedOption == 1 ? "> Return to lobby" : "Return to lobby");

}

void VictoryScene::ChangeToScenes()
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
