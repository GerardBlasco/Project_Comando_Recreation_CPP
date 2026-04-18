#include "InputMap.h"
#include <iostream>

InputMap::InputMap()
{
	
}

InputMap::InputMap(SDL_Keycode key, bool inverted)
{
    AddBinding(key, inverted);
}

InputMap::~InputMap()
{
    listeners.clear();
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

void InputMap::ExecuteListeners(InputEvent type)
{
    for (std::function<void()> function : listeners[type]) {
        function();
    }
}

void InputMap::CheckIfKeyPressed(std::map<int, bool>& keyDown)
{
    bool keyPressed = false;

    cancelled = false;

    for (auto& key : keys)
    {
        if (keyDown[key.first])
        {
            keyPressed = true;

            ToggleTrigger();

            performed = true;
            value = key.second;

            ExecuteListeners(InputEvent::Performed);

            if (triggered) {
                ExecuteListeners(InputEvent::Triggered);
            }

            break;
        }
    }

    if (!keyPressed) {
        if (performed) {
            cancelled = true;
            ExecuteListeners(InputEvent::Cancelled);
        }

        canTrigger = true;
        performed = false;
        value = 0;
    }
}

void InputMap::AddListener(std::function<void()> function, InputEvent event)
{
    listeners[event].push_back(function);
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

