#ifndef FIELD_BUILDER_H
#define FIELD_BUILDER_H

#include <fstream>
#include <cstdlib>
#include <ctime>

#include "field.h"
#include "../Structs/sample.h"

class FieldBuilder
{
public:
    FieldBuilder();
    ~FieldBuilder();

    void loadSampleFromFile(std::string fileName);
    
    void build();
    Field *getResult();

private:
    void reset();
    
    FieldSample *samples;
    size_t samplesLength;

    Field *target;
};

#endif // FIELD_BUILDER_H