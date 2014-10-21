
#include "Globals.h"

int SCREEN_WIDTH = 1200;
int SCREEN_HEIGHT = 900;
int TILE_WIDTH = 0;
int TILE_HEIGHT = 0;

int offsetX = 0;
int offsetY = 0;
int offsetdx = 10;
int offsetdy = 10;

std::shared_ptr<TextureMap> txtMap(new TextureMap());
std::shared_ptr<EnemyTextures> enemyMap(new EnemyTextures());

int TileSheetRows = 2;
int TileSheetCols = 2;

void Tokenize(const std::string& str,
                      std::vector<std::string>& tokens,
                      const std::string& delimiters)
{
    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

void AddTextureToTileTxtMap(std::string txtPath, std::string key)
{
	std::shared_ptr<sf::Texture> tempText(new sf::Texture());
	if(!(*tempText).loadFromFile(txtPath))
	{
		std::cout << " texture was not loaded!" << std::endl;
	}
	txtMap->insert(MapPair(key, tempText));
}

