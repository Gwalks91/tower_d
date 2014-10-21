
#ifndef TILE_H
#define TILE_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Globals.h"
#include "ClickableObject.h"

class Tile
{
private:
	int tileNum;
	int positionX;
	int positionY;
	int width;
	int height;

	bool canPlaceOn;
	bool walkable;

	RectPtr boundingRect;

	SpritePtr tImage;

	void makeSprite();
public:
	Tile();
	Tile(int TileNum, int posX, int posY);
	~Tile();
	void setCanPlaceOn();
	void setWalkable();
	bool getWalkable();
	sf::IntRect getRect();
	void update(float deltaTime);
	void draw(sf::RenderWindow* window);
};

#endif