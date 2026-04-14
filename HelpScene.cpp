#include "HelpScene.h"
#include "CreditsScene.h"
#include "GraphicsInterface.h"
#include "IntroScene.h"
#include "Game.h"
#include "InputSystem.h"
#include "MenuScene.h"

HelpScene::HelpScene(GraphicsInterface* GI): Scene(GI)
{
	selectedOption = 0;

	InputSystem::CreateMap("GoBack");
	InputSystem::Map("GoBack")->AddBinding(SDLK_R);
	InputSystem::Map("GoBack")->AddListener(this, &HelpScene::HandleInput, InputEvent::Triggered);
}

HelpScene::~HelpScene()
{
	InputSystem::DeleteMap("GoBack");
}

void HelpScene::Update()
{
}

void HelpScene::Render()
{
	GI->DrawText("Bienvenido al menu de ayuda, te muestro los bindings que se usan en este juego: ", 100, 120);
	GI->DrawText("Movimiento del personaje: WASD",100,160);
	GI->DrawText("Disparo de el arma principal: Click derecho", 100, 200);
	GI->DrawText("Disparo de el arma secundaria: Click izquierdo", 100, 230);

	GI->DrawText((selectedOption == 0 ? "> Salir al menu principal" : "> Salir al menu principal"), 100, 270);
}

void HelpScene::HandleInput()
{
	Game::ChangeScene(new MenuScene(GI));
}
