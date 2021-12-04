#ifndef FIELD_PAINTER_H
#define FIELD_PAINTER_H

#include <SFML/Graphics.hpp>

#include "../Field/field.h"
#include "../Entity/Item/item.h"
#include "../Entity/Alive/Hero/hero.h"
#include "../Entity/Alive/Enemy/Slime/slime.h"
#include "../Entity/Alive/Enemy/Goblin/goblin.h"
#include "../Entity/Alive/Enemy/Troll/troll.h"

class Drawer
{
public:
    Drawer(Field *, sf::Vector2u);

    void loadTileset(const char* img);
    void loadEnemies(const char* img);
    void loadHero(const char* img);
    void loadItems(const char* img);

    void loadFont(const char* img, size_t fontSize);

    void draw(sf::RenderTarget& target);

private:
    void drawEnemies(sf::RenderTarget& target);
    void drawItems(sf::RenderTarget& target);
    void drawHero(sf::RenderTarget& target);

    sf::Font font;
    sf::Text info;

    sf::Texture tileset;
    sf::VertexArray vertices;

    sf::Texture heroTexture;
    sf::Sprite heroSprite;

    sf::Texture enemiesTexture;
    sf::Sprite enemiesSprite;

    sf::Texture itemsTexture;
    sf::Sprite itemsSprite;

    sf::Vector2u tileSize;

    Field *field;
};

#endif // FIELD_PAINTER_H
