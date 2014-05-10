
#include "TileMap.h"

TileMap::TileMap()
{
	LoadTileMap();
}

TileMap::~TileMap()
{
	
	for(int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			delete tileMap[i][j];
		}
	}
	
}


void TileMap::LoadTileMap()
{
	int currentRow = 0;
	level.open("level.txt");

	if(!level.good())
		std::cout << "Level text file did not load!" << std::endl; 

	getline(level, str);
	std::vector <std::string> token;
	Tokenize(str, token, ", ");

	//Sets up the txtWidth, txtHeight, and tileSheet with the 
	// values in the level.txt
	TILE_WIDTH = atoi(token[2].c_str());
	TILE_HEIGHT = atoi(token[3].c_str());
	TileSheetRows = atoi(token[4].c_str());
	TileSheetCols = atoi(token[5].c_str());

	AddTexture("Images/" + token[6], "Tiles");	
	AddTexture("Images/Blank.png", "Blank");

	mapWidth = TILE_WIDTH * atoi(token[1].c_str());
	mapHeight = TILE_HEIGHT * atoi(token[0].c_str());

	token.clear();

	while(!level.eof()) 
	{
		getline(level, str);
		Tokenize(str, token);
		for(int i = 0; i < token.size(); i++)
		{
			tileMap[currentRow][i] = new Tile(atoi(token[i].c_str()), i * TILE_HEIGHT, currentRow * TILE_WIDTH );
		}
		currentRow++;
		token.clear();
	}
	level.close();
}


int TileMap::getMapWidth()
{
	return mapWidth;
}

int TileMap::getMapHeight()
{
	return mapHeight;
}

void TileMap::update(float deltaTime)
{
	for(int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			tileMap[i][j]->update(deltaTime);
		}
	}
}

void TileMap::draw(sf::RenderWindow* w)
{
	for(int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			tileMap[i][j]->draw(w);
		}
	}
}

