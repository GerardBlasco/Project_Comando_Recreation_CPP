#include "InputSystem.h"
#include "SDL3/SDL.h"
#include <Windows.h>

std::map<int, bool> InputSystem::keyDown;
std::map<std::string, InputMap*> InputSystem::maps;

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
	delete maps.find(name)->second;

	maps.erase(name);
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
	for (auto& pair : maps) {
		pair.second->CheckIfKeyPressed(keyDown);
	}
}
