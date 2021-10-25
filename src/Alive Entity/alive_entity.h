#ifndef ALIVE_ENTITY_H
#define ALIVE_ENTITY_H

struct Stat
{
    unsigned int value;
    unsigned int maxValue;

    friend struct Stat& operator+(const struct Stat& s1, const struct Stat& s2)
    {
        return s1 + s2 
    }
};


class AliveEntity
{
public:

private:
    size_t 
};

#endif // ALIVE_ENTITY_H