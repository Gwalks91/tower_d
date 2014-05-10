
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML\Graphics.hpp>

#include "Globals.h"

class InputManager
{
private:
	void checkMouseClick();
	void checkKeyboard();
	void screenMovement();
public:
	InputManager();
	void checkInput();
};

#endif