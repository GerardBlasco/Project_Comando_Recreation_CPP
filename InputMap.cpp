#include "InputMap.h"
#include <iostream>

InputMap::InputMap()
{
	
}

InputMap::InputMap(SDL_Keycode key, bool inverted)
{
    AddBinding(key, inverted);
}

void InputMap::AddBinding(SDL_Keycode key, bool inverted)
{
    float value = 1.f;

    if (inverted) {
        value = -1.f;
    }

	keys[key] = value;
}

void InputMap::RemoveBinding(SDL_Keycode key)
{
    keys.erase(key);
}

void InputMap::ExecuteListeners()
{
    for (std::function<void()> function : listeners) {
        function();
    }
}

void InputMap::CheckIfKeyPressed(std::map<int, bool>& keyDown)
{
    for (auto& key : keys)
    {
        if (keyDown[key.first])
        {
            ToggleTrigger();

            performed = true;
            value = key.second;

            ExecuteListeners();
            break;
        }
        else {
            canTrigger = true;

            performed = false;
            value = 0;
        }
    }
}

void InputMap::AddListener(std::function<void()> function)
{
    listeners.push_back(function);
}

void InputMap::ToggleTrigger()
{
    if (canTrigger) {
        canTrigger = false;
        triggered = true;
    }
    else {
        triggered = false;
    }
}

float InputMap::ReadFloat()
{
    return value;
}

