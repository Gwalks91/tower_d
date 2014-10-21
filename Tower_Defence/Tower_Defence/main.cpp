
#include <iostream>
#include <fstream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Globals.h"
#include "GlobalEngine.h"


int main()
{
	engine = new Engine();

    while (engine->window->isOpen())
    {
        sf::Event event;
        while (engine->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                engine->window->close();
        }

		engine->handleInput();
		engine->update();
		engine->draw();

    }
	delete engine;

    return 0;
}