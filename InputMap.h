#pragma once
#include "SDL3/SDL.h"
#include "InputEvent.h"
#include <vector>
#include <map>
#include <functional>

class InputMap
{
public:
	bool triggered = false;
	bool performed = false;
	bool cancelled = false;

	InputMap();
	InputMap(SDL_Keycode key, bool inverted = false);
	~InputMap();
	void AddBinding(SDL_Keycode key, bool inverted = false);
	void RemoveBinding(SDL_Keycode key);

	template<class T>
	void AddListener(T* object, void (T::* function)(), InputEvent event = InputEvent::Performed) {
		listeners[event].push_back([object, function]() {
			(object->*function)();
		});
	}

	void CheckIfKeyPressed(std::map<int, bool> &keyDown);

	float ReadFloat();

private:
	bool canTrigger = true;
	float value = 0;

	std::map<SDL_Keycode, float> keys;
	std::map<InputEvent, std::vector<std::function<void()>>> listeners;

	void AddListener(std::function<void()> function, InputEvent event = InputEvent::Performed);
	void ExecuteListeners(InputEvent type);

	void ToggleTrigger();
};

