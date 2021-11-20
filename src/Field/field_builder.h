#ifndef FIELD_BUILDER_H
#define FIELD_BUILDER_H

#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "field.h"
#include "../Structs/sample.h"

enum Difficulty {EASY, NORMAL, HARD};

class FieldBuilder
{
public:
    FieldBuilder();
    ~FieldBuilder();

    void loadSampleFromFile(std::string fileName);

    void setDifficulty(Difficulty diff);
    void spawnEntities(std::vector<Entity*> &);
    void spawnHero(Hero*);

    
    void build();
    Field *getResult();

private:
    std::vector<Tile*> getFreeTiles();
    void reset();
    bool loaded;
    
    FieldSample *samples;
    size_t samplesLength;

    unsigned short difficulty;

    Field *target;
};

#endif // FIELD_BUILDER_H
