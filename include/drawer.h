#ifndef FIELD_PAINTER_H
#define FIELD_PAINTER_H

#include <SFML/Graphics.hpp>

#include "field.h"

class Drawer : public sf::Drawable, public sf::Transformable
{
public:
    Drawer(Field *);

    void loadFromFile(const char* tileset, sf::Vector2u tileSize);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

    Field *target;
};

#endif // FIELD_PAINTER_H
