
#include "InputManager.h"

InputManager::InputManager()
{
}

//Public function that is called to check all of the input.
void InputManager::checkInput()
{
	checkMouseClick();
	checkKeyboard();
}

//Check the mouse click events
void InputManager::checkMouseClick()
{

}

//Check all the keyboard events
void InputManager::checkKeyboard()
{
	screenMovement();
}

//Check to see if the keyboard events are the ones to
//move the screen
void InputManager::screenMovement()
{
	/*
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && offsetX >= -(tileMap->getMapWidth() - SCREEN_WIDTH))
	{
		offsetX -= offsetdx;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && offsetX <= 0)
	{
		offsetX += offsetdx;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && offsetY <= 0)
	{
		offsetY += offsetdy;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && offsetY >= -(tileMap->getMapHeight() - SCREEN_HEIGHT))
	{
		offsetY -= offsetdy;
	}
	*/
}