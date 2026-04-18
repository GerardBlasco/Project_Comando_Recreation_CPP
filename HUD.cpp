#include "HUD.h"
#include "Scene.h"
#include "Player.h"

HUD::HUD(Scene* myScene) :Actor(myScene)
{

}

void HUD::Render()
{
	Player* player = nullptr; //Se empieza con un puntero vacio del player

	//Busca el player en escena
	for (Actor* actor : myScene->GetAllActors()) //Recorremos todos los actores en escena
	{
		if (actor->tag == "Player")   //Si tiene el tag player, entonces es el jugador
		{
			player = (Player*)actor; //Aqui lo guardamos en player (el actor)
			break;
		}
	}


	int score = player ? player->GetScore() : 0;
	std::cout << "Score actual: " << score << std::endl;


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
