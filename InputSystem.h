#pragma once
#include <iostream>
#include <map>
#include "InputMap.h"

class InputSystem
{
public:
	static void CreateMap(std::string name);
	static void CreateMap(std::string name, SDL_Keycode key, bool inverted = false);
	static void DeleteMap(std::string name);

	static InputMap* Map(const std::string name);

	static void Update();
	
	static void Delta(float &x, float &y);
	static float DeltaX();
	static float DeltaY();

	static bool EventQuit();

private:
	static std::map<int, bool> keyDown;
	static std::map<std::string, InputMap*> maps;

	~InputSystem();

	static void UpdateInputs();
	static void UpdateMaps();

	static bool eventQuit;
	static float deltaX;
	static float deltaY;
};