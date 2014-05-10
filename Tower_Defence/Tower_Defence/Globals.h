
#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>
#include <iostream>

//#include "Engine.h"

typedef std::map<std::string, sf::Texture*> TextureMap;
typedef std::pair<std::string, sf::Texture*> MapPair;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern int TILE_WIDTH;
extern int TILE_HEIGHT;

extern int offsetX;
extern int offsetY;
extern int offsetdx;
extern int offsetdy;

extern TextureMap* txtMap;

extern int TileSheetRows;
extern int TileSheetCols;

#define rows 20
#define cols 20

void Tokenize(const std::string& str,
                      std::vector<std::string>& tokens,
                      const std::string& delimiters = " ");

void AddTexture(std::string txtPath, std::string key);

#endif