#pragma once
#include "Scene.h"
#include "Game.h"
class MenuScene : public Scene
{
public:
	MenuScene(GraphicsInterface* GI);
	void Update() override;
	void Render() override;
	void HandleInput();

private:
	int selectedOption; //Opcion de jugar, opciones, creditos i salir
};

