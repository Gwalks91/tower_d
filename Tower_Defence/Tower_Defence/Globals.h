
#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>

typedef std::map<std::string, sf::Texture*> TextureMap;
typedef std::pair<std::string, sf::Texture*> MapPair;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern int TILE_WIDTH;
extern int TILE_HEIGHT;

extern TextureMap* txtMap;

extern int TileSheetRows;
extern int TileSheetCols;

#endif