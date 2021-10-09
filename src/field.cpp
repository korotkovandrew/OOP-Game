#include "../include/field.h"

// Constructors & Destructor

Field::Field(std::string tilesetImg,
             const int* tileMap, 
             int tileSize,
             size_t width, 
             size_t height)
: tileMap(tileMap),
  width(width), 
  height(height) 
{
  sf::Sprite tileSprite;
  int tileType;
  bool passable;

  // Loading set of tiles from file
  tileset.loadFromFile(tilesetImg);


  // Tile sprites initialisation
  tiles = new Tile*[width];

  for (size_t x = 0; x < width; x++) {
    tiles[x] = new Tile[height];

    for (size_t y = 0; y < height; y++) {
      tileSprite.setTexture(tileset);
      tileType = tileMap[x + y*width];

      tileSprite.setTextureRect(sf::IntRect(tileSize*(tileType%2), 
                                            tileSize*(tileType/2), 
                                            tileSize, tileSize));
      tileSprite.setPosition(sf::Vector2f(x*tileSize, y*tileSize));

      passable = (tileType == WALL);
      tiles[x][y] = Tile(tileSprite, tileMap[x + y*width], passable);
    }
  }
}

Field::~Field()
{
  for (int x = 0; x < width; x++)
    delete [] tiles[x];
  delete [] tiles;
}

Field::Field(const Field& other)
: tileMap(other.tileMap),
  tileset(other.tileset), 
  width(other.width), 
  height(other.height) 
{
  tiles = new Tile*[width];
  for (size_t x = 0; x < width; x++) {
    tiles[x] = new Tile[height];
    for (size_t y = 0; y < height; y++) {
      tiles[x][y] = other.tiles[x][y];
    }
  }
}

Field& Field::operator=(const Field& other)
{
  for (int x = 0; x < width; x++)
    delete [] tiles[x];
  delete [] tiles;

  tileMap = other.tileMap;
  tileset = other.tileset;
  width   = other.width;
  height  = other.height;

  tiles = new Tile*[width];
  for (size_t x = 0; x < width; x++) {
    tiles[x] = new Tile[height];
    for (size_t y = 0; y < height; y++) {
      tiles[x][y] = other.tiles[x][y];
    }
  }
  return *this;
}

Field::Field(Field&& other)
: tileMap(other.tileMap),
  tileset(other.tileset), 
  width(other.width), 
  height(other.height),
  tiles(other.tiles)
{
  if (&other == this) return;
  other.tiles = nullptr;
}

Field& Field::operator=(Field&& other)
{
  if (&other != this) return *this;

  for (int x = 0; x < width; x++)
    delete [] tiles[x];
  delete [] tiles;

  tileMap = other.tileMap;
  tileset = other.tileset;
  width   = other.width;
  height  = other.height;
  tiles   = other.tiles;

  return *this;
}

// Public Functions

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &tileset;

  for (size_t x = 0; x < width; x++) {
    for (size_t y = 0; y < height; y++) {
      target.draw(tiles[x][y].getSprite(), states);
    }
  }
}