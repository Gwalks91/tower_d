
#include <iostream>
#include <fstream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Globals.h"
#include "Engine.h"

int main()
{
	Engine* eng = new Engine();

    while (eng->window->isOpen())
    {
        sf::Event event;
        while (eng->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                eng->window->close();
        }

		eng->handleInput();
		eng->update();
		eng->draw();

    }
	delete eng;

	delete txtMap->at("Tiles");
	delete txtMap->at("Blank");

    return 0;
}