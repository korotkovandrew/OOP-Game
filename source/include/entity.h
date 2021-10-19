#ifndef ENTITY_H
#define ENTITY_H

class Entity 
{
public:
    virtual ~Entity() = 0;

    virtual Entity& operator=(const Entity&);
};

#endif // ENTITY_H