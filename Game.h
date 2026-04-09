#pragma once
#include <map>
#include "Scene.h"

class Game
{
public:
	static void Create();
	static void Play();
	static void Destroy();


private:
	static Game* instance;
	static float DeltaTime;

	class GraphicsInterface* GI;
	bool game_end = false;

	Scene* currentScene;

	Game();
	~Game();

	void Loop();
	void Update();
	void Render();
};

