#include "HUD.h"
#include "Scene.h"

HUD::HUD(Scene* myScene):Actor(myScene)
{

}

void HUD::Render()
{

	myScene->GI->DrawText("Score: ", 100, 600);
	myScene->GI->DrawText("0 ", 220, 600);

	Transform t;
	t.position = { 300, 600 };   // posicion en pantalla
	t.rotation = 0;            // sin rotacion
	t.scale = { 1, 1 };          // escala normal

	myScene->GI->DrawSprite("icon_granade.png", t, 20, 20);
	myScene->GI->DrawText("0 ", 450, 600);

	myScene->GI->DrawText("MEN: ", 500, 600);
	myScene->GI->DrawText("0 ", 600, 600);

	myScene->GI->DrawText("HI: ", 700, 600);
	myScene->GI->DrawText("0 ", 800, 600);
}
