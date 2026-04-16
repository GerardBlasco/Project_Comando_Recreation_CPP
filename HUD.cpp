#include "HUD.h"
#include "CreditsScene.h"
#include "GraphicsInterface.h"
#include "IntroScene.h"
#include "Game.h"
#include "InputSystem.h"
#include "MenuScene.h"

HUD::HUD(GraphicsInterface* GI)
{
	this-> GI = GI;
}

void HUD::Update() 
{

}

void HUD::Render()
{
	GI->DrawText("Score: ", 100, 600);

}

void HUD::HandleInput()
{

}