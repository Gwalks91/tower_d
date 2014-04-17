
#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "Globals.h"
#include "Tile.h"

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tower Defence");
	
	/*
	std::ifstream myfile;
	myfile.open ("example.txt");
	if(!myfile.good())
		return -1;
	while (!myfile.eof())
	{


	}
	myfile << "Writing this to a file.\n";
	myfile.close();
	*/

	sf::Texture* tempText = new sf::Texture();
	if(!(*tempText).loadFromFile("Images/TileSheet.png"))
	{
		std::cout << " texture was not loaded!" << std::endl;
		window->close();
	}
	txtMap->insert(MapPair("Tiles", tempText));

	Tile* t = new Tile(3, 0, 0);
	Tile* t1 = new Tile(1, 100, 0);
	Tile* t2 = new Tile(2, 0, 100);
	Tile* t3 = new Tile(0, 100, 100);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
		t->draw(window);
		t1->draw(window);
		t2->draw(window);
		t3->draw(window);
        window->display();
    }
	delete tempText;
	delete window;
	delete t;
	delete t1;
	delete t2;
	delete t3;
    return 0;
}