#include "HelpScene.h"
#include "InputSystem.h"
#include "Text.h"
#include "Game.h"
#include "MenuScene.h"

HelpScene::HelpScene(GraphicsInterface* GI):Scene(GI)
{
	InputSystem::CreateMap("GoBack");
	InputSystem::Map("GoBack")->AddBinding(SDLK_R);
	InputSystem::Map("GoBack")->AddListener(this, &HelpScene::HandleInput, InputEvent::Triggered);

	actors.push_back(new Text(this, "Bienvenido al menu de ayuda, te muestro los bindings que se usan en este juego: ", Vector2(100, 120)));
	actors.push_back(new Text(this, "Movimiento del personaje: WASD", Vector2(100, 160)));
	actors.push_back(new Text(this, "Disparo de el arma principal: Click derecho", Vector2(100, 200)));
	actors.push_back(new Text(this, "Disparo de el arma secundaria: Click izquierdo", Vector2(100, 230)));
	actors.push_back(new Text(this, "> Salir al menu principal", Vector2(100, 270)));
}

HelpScene::~HelpScene()
{
	//InputSystem::DeleteMap("GoBack");
}

void HelpScene::HandleInput()
{
	Game::ChangeScene(new MenuScene(GI));
}