#include "drawer.h"

/* Constructors and Destructors */
Drawer::Drawer(Field *field, sf::Vector2u tileSize)
    : field(field),
      tileSize(tileSize) {}

/* Public Functions */
void Drawer::loadTileset(const char* img)
{
    if (!tileset.loadFromFile(img)) 
        throw std::runtime_error("Error: Read Tileset File");

    size_t w = field->getWidth();
    size_t h = field->getHeight();

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(w * h * 4);

    for (size_t x = 0; x < w; ++x)
        for (size_t y = 0; y < h; ++y)
        {
            unsigned short tileNumber = field->tiles[x][y].getType();

            int tu = tileNumber % (tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (tileset.getSize().x / tileSize.x);

            sf::Vertex* quad = &vertices[(x + y * w) * 4];

            quad[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);
            quad[1].position = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y);
            quad[2].position = sf::Vector2f((x + 1) * tileSize.x, (y + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y);

            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
}

void Drawer::loadHero(const char* img)
{
    if (!heroTexture.loadFromFile(img)) 
        throw std::runtime_error("Error: Read Hero Texture File");
    heroSprite.setTexture(heroTexture);
}

void Drawer::loadEnemies(const char* img)
{
    if (!enemiesTexture.loadFromFile(img)) 
        throw std::runtime_error("Error: Read Enemies Texture File");
    enemiesSprite.setTexture(enemiesTexture);
}

void Drawer::loadItems(const char* img)
{
    if (!itemsTexture.loadFromFile(img)) 
        throw std::runtime_error("Error: Read Items Texture File");
    itemsSprite.setTexture(itemsTexture);
}

void Drawer::loadFont(const char* img, size_t fontSize)
{
    font.loadFromFile(img);
    info.setFont(font);
    info.setLetterSpacing(2);
    info.setCharacterSize(fontSize);
    info.setFillColor(sf::Color::Red);
    info.setPosition(0, field->getHeight() * tileSize.y - 4);
}

/* Private Functions */
void Drawer::draw(sf::RenderTarget& target)
{
    target.draw(vertices, &tileset);

    drawEnemies(target);
    drawItems(target);
    drawHero(target);

    auto hero = dynamic_cast<Hero*>(field->heroTile->getEntity());
    std::string s;
    s += " HP: " + std::to_string(hero->getHealth()) + "/" + std::to_string(hero->getMaxHealth());
    s += " DMG: " + std::to_string(hero->getDamage());
    s += " ARMOR: " + std::to_string(hero->getArmor());
    info.setString(s);
    target.draw(info);
    
} 

/* Private Functions */

void Drawer::drawEnemies(sf::RenderTarget& target)
{
    auto slimeid = typeid(Slime).name();
    auto goblinid = typeid(Goblin).name();
    auto trollid = typeid(Troll).name();
    for (auto tile: field->enemyTiles) {
        enemiesSprite.setPosition(tile->getX()*tileSize.x, tile->getY()*tileSize.y);
        auto eTypeid = typeid(*tile->getEntity()).name();
        if (eTypeid == typeid(Slime).name()) 
            enemiesSprite.setTextureRect(sf::IntRect(0, 0, tileSize.x, tileSize.y));
        else if (eTypeid == typeid(Goblin).name()) 
            enemiesSprite.setTextureRect(sf::IntRect(tileSize.x, 0, tileSize.x, tileSize.y));
        else if (eTypeid == typeid(Troll).name()) 
            enemiesSprite.setTextureRect(sf::IntRect(0, tileSize.y, tileSize.x, tileSize.y));

        target.draw(enemiesSprite, &enemiesTexture);
    }
}

void Drawer::drawItems(sf::RenderTarget& target)
{
    for (auto tile: field->itemTiles) {
        itemsSprite.setPosition(tile->getX()*tileSize.x, tile->getY()*tileSize.y);
        auto itemType = dynamic_cast<Item*>(tile->getEntity())->getType();
        if (itemType == HEAL) 
            itemsSprite.setTextureRect(sf::IntRect(0, 0, tileSize.x, tileSize.y));
        else if (itemType == DMG) 
            itemsSprite.setTextureRect(sf::IntRect(tileSize.x, 0, tileSize.x, tileSize.y));
        else if (itemType == ARMOR) 
            itemsSprite.setTextureRect(sf::IntRect(0, tileSize.y, tileSize.x, tileSize.y));
            
        target.draw(itemsSprite, &enemiesTexture);
    }
}

void Drawer::drawHero(sf::RenderTarget& target)
{
    heroSprite.setPosition(field->heroTile->getX() * tileSize.x, 
                           field->heroTile->getY() * tileSize.y);
    target.draw(heroSprite);
}
