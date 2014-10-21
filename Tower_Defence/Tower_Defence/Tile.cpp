
#include "Tile.h"

Tile::Tile()
	:tileNum(0), positionX(0), positionY(0), 
	width(TILE_WIDTH), height(TILE_HEIGHT),
	canPlaceOn(false), walkable(true),
	boundingRect(new sf::IntRect(positionX, positionY, width, height))
{
	makeSprite();
	tImage->setPosition(positionX + offsetX, positionY + offsetY);
}

Tile::Tile(int TileNum, int posX, int posY)
	:tileNum(TileNum), positionX(posX), positionY(posY), 
	width(TILE_WIDTH), height(TILE_HEIGHT),
	canPlaceOn(false), 
	boundingRect(new sf::IntRect(positionX, positionY, width, height))
{
	makeSprite();
	tImage->setPosition(positionX + offsetX, positionY + offsetY);
}

Tile::~Tile()
{
}

/*
Makes the tile sprite by checking the tileNumber
*/
void Tile::makeSprite()
{
	if( tileNum == -999)
	{
		tImage = SpritePtr(new sf::Sprite(*txtMap->at("Blank")));
		tImage->setTextureRect(sf::IntRect(0,0,TILE_WIDTH, TILE_HEIGHT));
	}
	else
	{
		tImage = SpritePtr(new sf::Sprite(*txtMap->at("Tiles")));
		if(tileNum == 0 || tileNum == -1 || tileNum == -2)
			tImage->setTextureRect(sf::IntRect(0,0,TILE_WIDTH, TILE_HEIGHT));
		else
		{
			tImage->setTextureRect(sf::IntRect(TILE_HEIGHT * (tileNum % TileSheetCols),
				TILE_WIDTH * (tileNum / TileSheetRows),TILE_WIDTH, TILE_HEIGHT));
		}
	}

}

//Changes the tile to see if a player can place a tower on it.
void Tile::setCanPlaceOn()
{
	canPlaceOn = !canPlaceOn;
}

void Tile::setWalkable()
{
	walkable = !walkable;
}

//Used for A* to check and see if it part of the usable path
bool Tile::getWalkable()
{
	return walkable;
}

sf::IntRect Tile::getRect()
{
	return *boundingRect;
}

void Tile::update(float deltaTime)
{
	tImage->setPosition(positionX + offsetX, positionY + offsetY);
}

void Tile::draw(sf::RenderWindow* window)
{
	window->draw(*tImage);
}

