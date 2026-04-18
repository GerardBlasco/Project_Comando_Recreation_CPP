#pragma once
#include "Actor.h"
#include "Player.h"
class HUD : public Actor
{
public:

	HUD(Scene* myScene, Player* player);
	virtual void Update();
	virtual void Render();

private:
	int playerScore;
	Player* player;
	int highScore;
	int health;
	int granadesQuantity;
};

