#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "tile.h"

enum {WALL, GROUND, ENTRANCE, EXIT};

class Field : public sf::Drawable, sf::Transformable
{
public:
  Field(std::string tilesetImg,
        const int* tileMap, 
        int tileSize,
        size_t width, 
        size_t height);

  ~Field();

  // Copy constructor 
  Field(const Field& other);

  // Copy operator
  Field& operator=(const Field& other);

  // Move constructor
  Field(Field&& other);

  // Move operator
  Field& operator=(Field&& other);

  // Draws field's cells in target 
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  // Getters 
  Tile& getTile(size_t x, size_t y);

private:
  Tile** tiles;
  const int* tileMap;

  sf::Texture tileset;
  size_t width;
  size_t height;
};


#endif // !FIELD_H
