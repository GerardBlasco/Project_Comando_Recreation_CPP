#include "PauseMenu.h"
#include "InputSystem.h"
#include "Game.h"
#include "MenuScene.h"
#include "IntroScene.h"

PauseMenu::PauseMenu(Scene* scene): Actor(scene)
{
	tag = "PauseMenu";

	InputSystem::Map("PauseMove")->AddListener(this, &PauseMenu::HandleInputs, InputEvent::Triggered);
	InputSystem::Map("PauseSelect")->AddListener(this, &PauseMenu::HandleInputs, InputEvent::Triggered);
}

void PauseMenu::Update() 
{
	if (!active) return;
	HandleInputs();
}

void PauseMenu::Render() 
{
	if (!active) return;
	ShowCanvas();
}

void PauseMenu::HandleInputs()
{
	if (!active) return;

	float value = InputSystem::Map("PauseMove")->ReadFloat(); //Lee el float de ese input -1 o 1

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


	if (InputSystem::Map("PauseSelect")->triggered)
	{
		switch (selectedOption)
		{
		case 0: // Return to game
			active = false;
			break;

		case 1: // Back to lobby
			Game::ChangeScene(new MenuScene(myScene->GI));
			break;
		}
	}

}

void PauseMenu::ShowCanvas()
{
	myScene->GI->DrawText("Pause Menu ", 400, 120);
	myScene->GI->DrawText(selectedOption == 0 ? "> Return to game" : "Return to game", 200, 500);
	myScene->GI->DrawText(selectedOption == 1 ? "> Return to lobby" : "Return to lobby", 500, 500);
	
}
