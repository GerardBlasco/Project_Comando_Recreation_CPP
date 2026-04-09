#pragma once
#include "SDL3/SDL.h"
#include <vector>
#include <map>
#include <functional>

class InputMap
{
public:
	bool triggered = false;
	bool performed = false;

	InputMap();
	InputMap(SDL_Keycode key, bool inverted = false);
	void AddBinding(SDL_Keycode key, bool inverted = false);
	void RemoveBinding(SDL_Keycode key);

	template<class T>
	void AddListener(T* object, void (T::* function)()) {
		listeners.push_back([object, function]() {
			(object->*function)();
		});
	}

	void CheckIfKeyPressed(std::map<int, bool> &keyDown);

	float ReadFloat();

private:
	bool canTrigger = true;
	float value = 0;

	std::map<SDL_Keycode, float> keys;
	std::vector<std::function<void()>> listeners;

	void AddListener(std::function<void()> function);
	void ExecuteListeners();

	void ToggleTrigger();
};

