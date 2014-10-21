
#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

typedef std::shared_ptr<sf::Texture> TexturePtr;
typedef std::tr1::shared_ptr<sf::Sprite> SpritePtr;
typedef std::shared_ptr<sf::IntRect> RectPtr;
typedef std::map<std::string, TexturePtr> TextureMap;
typedef std::pair<std::string, TexturePtr> MapPair;
typedef std::map<std::string, TexturePtr> EnemyTextures;


extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern int TILE_WIDTH;
extern int TILE_HEIGHT;

extern int offsetX;
extern int offsetY;
extern int offsetdx;
extern int offsetdy;

extern std::shared_ptr<TextureMap> txtMap;
extern std::shared_ptr<EnemyTextures> enemyMap;

extern int TileSheetRows;
extern int TileSheetCols;

#define rows 20
#define cols 20

void Tokenize(const std::string& str,
                      std::vector<std::string>& tokens,
                      const std::string& delimiters = " ");

void AddTextureToTileTxtMap(std::string txtPath, std::string key);
void AddTextureToEenemyTxtMap(std::string txtPath, std::string key);

#endif