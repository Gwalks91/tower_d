
#ifndef TILEMAP_H
#define TILEMAP_H

#include <fstream>

#include <SFML/Graphics.hpp>

#include "Globals.h"
#include "Tile.h"

class TileMap
{
private:
	std::string str;
	std::ifstream level;
	std::shared_ptr<Tile> tileMap[20][20];

	int mapWidth;
	int mapHeight;

	void LoadTileMap();
	
public:
	TileMap();
	~TileMap();
	int getMapWidth();
	int getMapHeight();
	void update(float deltaTime);
	void draw(sf::RenderWindow* w);
};

#endif