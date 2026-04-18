#include "CreditsScene.h"
#include "Game.h"
#include "MenuScene.h"
#include "Text.h"

CreditsScene::CreditsScene(GraphicsInterface* GI):Scene(GI)
{
	InputSystem::CreateMap("GoBackToMainMenu");
	InputSystem::Map("GoBackToMainMenu")->AddBinding(SDLK_RETURN);
	InputSystem::Map("GoBackToMainMenu")->AddListener(this, &CreditsScene::HandleInput, InputEvent::Triggered);

	actors.push_back(new Text(this, "Juego basado en el Commando Commodore 64", Vector2(100, 120)));
	actors.push_back(new Text(this, "Creadores: Gerard Blasco e Iris Frades", Vector2(100, 160)));
	actors.push_back(new Text(this, "Professor: Francisco Arias", Vector2(100, 200)));
	actors.push_back(new Text(this, "> Salir al menu principal", Vector2(100, 240)));
}

CreditsScene::~CreditsScene()
{
	InputSystem::DeleteMap("GoBackToMainMenu");
}

void CreditsScene::HandleInput()
{
	Game::ChangeScene(new MenuScene(GI));
}
