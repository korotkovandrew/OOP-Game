#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "tile.h"

enum Tiles {WALL, GROUND, ENTRANCE, EXIT};

class Field : public sf::Drawable, sf::Transformable
{
public:
  Field(std::string tilesetImg,
        const int* tileMap, 
        int tileSize,
        size_t width, 
        size_t height);
  ~Field();

  // Draws field's cells in target 
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
  Tile** tiles;
  sf::Texture tileset;

  const int* tileMap;
  size_t width;
  size_t height;
};


#endif // !FIELD_H
