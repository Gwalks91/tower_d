
#include "Engine.h"

Engine::Engine()
	:window(new sf::RenderWindow(sf::VideoMode(1200, 900), "Tower Defence")),
	gameClock(),
	tileMap(new TileMap()),
	deltaTime(0.0f)
{
}

Engine::~Engine()
{
	delete tileMap;
}

void Engine::handleInput()
{
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
}

void Engine::update()
{
	deltaTime = gameClock.getElapsedTime().asSeconds();
	tileMap->update(deltaTime);
	gameClock.restart();
}

void Engine::draw()
{
	window->clear();
	tileMap->draw(window);
	window->display();
}