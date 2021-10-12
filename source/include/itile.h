#ifndef ITILE_H
#define ITILE_H

#include <SFML/Graphics.hpp>

class ITile
{
public:
  bool virtual isPassable() = 0;
  bool virtual isEmpty() = 0;
};

#endif // !ITILE_H
