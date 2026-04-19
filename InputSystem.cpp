#include "InputSystem.h"
#include "SDL3/SDL.h"
#include <Windows.h>

std::map<int, bool> InputSystem::keyDown;
std::map<std::string, InputMap*> InputSystem::maps;
std::vector<std::string> InputSystem::mapsToDelete;

bool InputSystem::eventQuit = false;
float InputSystem::deltaX = 0;
float InputSystem::deltaY = 0;

void InputSystem::CreateMap(std::string name)
{
	maps[name] = new InputMap();
}

void InputSystem::CreateMap(std::string name, SDL_Keycode key, bool inverted)
{
	maps[name] = new InputMap(key, inverted);
}

void InputSystem::DeleteMap(std::string name)
{
	mapsToDelete.push_back(name);
}

void InputSystem::ResetInputs()
{
	keyDown.clear();
}

InputMap* InputSystem::Map(const std::string name)
{
	return maps.find(name)->second;
}

void InputSystem::Update()
{
	UpdateInputs();
	UpdateMaps();
}

void InputSystem::ClearMaps()
{
	for (auto& pair : maps) {
		delete pair.second;
	}

	maps.clear();
	mapsToDelete.clear();
	keyDown.clear();
}

void InputSystem::ClearListeners()
{
	for (auto& pair : maps)
	{
		if (pair.second)
			pair.second->ClearListeners();
	}
}

void InputSystem::Delta(float& x, float& y)
{
	x = deltaX;
	y = deltaY;
}

float InputSystem::DeltaX()
{
	return deltaX;
}

float InputSystem::DeltaY()
{
	return deltaY;
}

bool InputSystem::EventQuit()
{
	return eventQuit;
}

InputSystem::~InputSystem()
{
	for (auto& map : maps) {
		delete map.second;
	}
}

void InputSystem::UpdateInputs()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			eventQuit = true;
			break;
		case SDL_EVENT_KEY_DOWN:
			keyDown[event.key.key] = true;
			break;
		case SDL_EVENT_KEY_UP:
			keyDown[event.key.key] = false;
			break;
		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			keyDown[event.button.button] = true;
			break;
		case SDL_EVENT_MOUSE_BUTTON_UP:
			keyDown[event.button.button] = false;
			break;
		case SDL_EVENT_MOUSE_MOTION:
			deltaX = event.motion.x;
			deltaY = event.motion.y;
			break;
		case SDL_EVENT_MOUSE_WHEEL:
			break;
		}
	}
}

void InputSystem::UpdateMaps()
{
	for (std::string name : mapsToDelete) {
		std::map<std::string, InputMap*>::iterator it = maps.find(name);
		if (it != maps.end()) {
			delete it->second;
			maps.erase(it);
		}
	}
	mapsToDelete.clear();

	for (auto& pair : maps) {
		if (pair.second) {
			pair.second->CheckIfKeyPressed(keyDown);
		}
	}
}
