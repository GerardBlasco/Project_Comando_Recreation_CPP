#pragma once
#include "Scene.h"
#include "Game.h"
class MenuScene : public Scene
{
public:
	MenuScene(GraphicsInterface* GI);
	~MenuScene();
	void Update() override;
	void Render() override;
	void HandleInput();
	void ChangeToScene();

private:
	int selectedOption; //Opcion de jugar, opciones, creditos i salir
};

