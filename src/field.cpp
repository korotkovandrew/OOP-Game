#include "../include/field.h"

Field::Field(std::string tilesetImg,
             const int* tileMap, 
             int tileSize,
             size_t width, 
             size_t height)
            : tileMap(tileMap), width(width), height(height) 
{
  sf::Sprite tileSprite;
  int tileType;
  int* gTileMap;
  bool passable;

  // Loading set of tiles from file
  tileset.loadFromFile(tilesetImg);

  // Memory allocation
  tiles = new Tile*[width];
  for (size_t x = 0; x < width; x++)
    tiles[x] = new Tile[height];
  
  //! Generating field pattern if it wasn't premade
  /*
  if (!tileMap) {
    int entrance, exit;

    std::srand(std::time(nullptr));

    entrance = std::rand() % width*height;
    exit = std::rand() % width*height + (width*height/2);

    gTileMap = new int[width*height];
    for (size_t i = 0; i < width*height; i++) {
      gTileMap[i] = GROUND;
      if ((i % width) == 0  ||
          (i % width) + 1 == 0 ||
          (i < height) ||
          (i > width*height - height)) {
        gTileMap[i] = WALL;
      }
      if (i == entrance) gTileMap[i] = ENTRANCE;
      if (i == exit) gTileMap[i] = EXIT;
    }
  }
  */

  // Tile sprites initialisation
  for (size_t x = 0; x < width; x++) {
    for (size_t y = 0; y < height; y++) {
      tileSprite.setTexture(tileset);
      tileType = tileMap ? tileMap[x + y*width] : gTileMap[x + y*width];

      tileSprite.setTextureRect(sf::IntRect(tileSize*(tileType%2), 
                                            tileSize*(tileType/2), 
                                            tileSize, 
                                            tileSize));
      
      tileSprite.setPosition(sf::Vector2f(x*tileSize, y*tileSize));

      passable = (tileType == WALL);
      tiles[x][y].init(tileSprite, passable);
    }
  }
}

Field::~Field()
{
  for (int x = 0; x < width; x++)
    delete [] tiles[x];
  delete [] tiles;
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &tileset;

  for (size_t x = 0; x < width; x++)
    for (size_t y = 0; y < height; y++)
      target.draw(tiles[x][y].getSprite(), states);
}