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
	GI->DrawText("0 ", 220, 600);

	Transform t;
	t.position = { 300, 600 };   // posición en pantalla
	t.rotation = 0;            // sin rotación
	t.scale = { 1, 1 };          // escala normal

	GI->DrawSprite("Assets\Imagenes\GranadaIcon.png", t, 20, 20);
	GI->DrawText("0 ", 450, 600);

	GI->DrawText("MEN: ", 500, 600);
	GI->DrawText("0 ", 600, 600);

	GI->DrawText("HI: ", 700, 600);
	GI->DrawText("0 ", 800, 600);

	
}

void HUD::HandleInput()
{

}