
#ifndef ENGINE_H
#define ENGINE_H

#include <SFML\Graphics.hpp>

//#include "Globals.h"
#include "TileMap.h"

class Engine
{
private:
	sf::Clock gameClock;
	
	TileMap* tileMap;

	float deltaTime;
public:
	sf::RenderWindow* window;

	Engine();
	~Engine();
	void handleInput();
	void update();
	void draw();
	
};

#endif