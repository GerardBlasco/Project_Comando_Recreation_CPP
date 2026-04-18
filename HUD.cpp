#include "HUD.h"
#include "Scene.h"
#include "Player.h"
#include <sstream>

HUD::HUD(Scene* myScene, Player* player) :Actor(myScene)
{
	this->player = player;
	playerScore = 0;
	highScore = 0;
	health = 5;
	granadesQuantity = 5;
}
void HUD::Update() 
{
	playerScore = player->GetScore(); //Guardamos la score 
	health = player->GetHealth(); //guardamos las vidas que le quedan
	granadesQuantity = player->GetGranades();//guardamos la cantidad de granadas que le quedan

	if (playerScore > highScore) 
	{
		highScore = playerScore;
	}
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
	myScene->GI->DrawText("Score: ", 100, 600);
	
	//Para imprimir el numero de score
	std::stringstream ss;
	ss << playerScore;
	myScene->GI->DrawText(ss.str(), 220, 600);

	Transform t;
	t.position = { 400, 620 };   // posicion en pantalla
	t.rotation = 0;            // sin rotacion
	t.scale = { 1, 1 };          // escala normal

	//Mostrar granadas que tiene
	myScene->GI->DrawSprite("icon_granade.png", t, 40, 40);
	myScene->GI->DrawText("= ", 430, 600);

	std::stringstream ss4;
	ss4 << granadesQuantity;
	myScene->GI->DrawText(ss4.str(), 450, 600);

	//Mostrar vidas
	myScene->GI->DrawText("MEN: ", 500, 600);

	std::stringstream ss3;
	ss3 << health;
	myScene->GI->DrawText(ss3.str(), 600, 600);

	//Mostrar score mas alta
	myScene->GI->DrawText("HI: ", 700, 600);

	std::stringstream ss2;
	ss2 << highScore;
	myScene->GI->DrawText(ss2.str(), 800, 600);
}
