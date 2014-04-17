
#include "Tile.h"

Tile::Tile()
	:tileNum(0), positionX(0), positionY(0), 
	width(TILE_WIDTH), height(TILE_HEIGHT),
	canPlaceOn(false), walkable(true),
	boundingRect(new sf::IntRect(positionX, positionY, width, height))
{
	makeSprite();
	tImage->setPosition(positionX, positionY);
}

Tile::Tile(int TileNum, int posX, int posY)
	:tileNum(TileNum), positionX(posX), positionY(posY), 
	width(TILE_WIDTH), height(TILE_HEIGHT),
	canPlaceOn(false), 
	boundingRect(new sf::IntRect(positionX, positionY, width, height))
{
	makeSprite();
	tImage->setPosition(positionX, positionY);
}

Tile::~Tile()
{
	delete boundingRect;
	delete tImage;
}

/*
Makes the tile sprite by checking the tileNumber
*/
void Tile::makeSprite()
{
	if(tileNum < TileSheetRows * TileSheetCols)
	{
		tImage = new sf::Sprite((*txtMap->at("Tiles")));
		if(tileNum == 0)
			tImage->setTextureRect(sf::IntRect(0,0,TILE_WIDTH, TILE_HEIGHT));
		else
		{
			tImage->setTextureRect(sf::IntRect(TILE_HEIGHT * (tileNum % TileSheetCols),
				TILE_WIDTH * (tileNum / TileSheetRows),TILE_WIDTH, TILE_HEIGHT));
		}
	}
	else
	{
		std::cout << "The tile type you are typing to make does not have a texture mapped to it!" << std::endl;
	}
}

//Changes the tile to see if a player can place a tower on it.
void Tile::setCanPlaceOn()
{
	canPlaceOn = !canPlaceOn;
}

//Used for A* to check and see if it part of the usable path
bool Tile::checkWalkable()
{
	return walkable;
}

sf::IntRect Tile::getRect()
{
	return *boundingRect;
}

void Tile::update(float deltaTime)
{

}
void Tile::draw(sf::RenderWindow* window)
{
	window->draw(*tImage);
}

