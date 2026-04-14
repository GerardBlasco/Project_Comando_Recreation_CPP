#pragma once
#include <map>
#include "Scene.h"

class Game
{
public:
	static void Create();
	static void Play();
	static void Destroy();
	static void ChangeScene(Scene* newScene);


	static float DeltaTime();

private:
	static Game* instance;

	class GraphicsInterface* GI;
	bool game_end = false;
	static float deltaTime;

	Scene* currentScene;

	Game();
	~Game();

	void Loop();
	void Update();
	void Render();
};

