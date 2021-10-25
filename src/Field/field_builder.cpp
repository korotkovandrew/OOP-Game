#include "field_builder.h"

/* Constructors and Destructors */

FieldBuilder::FieldBuilder()
    : target(new Field()),
      samples(nullptr),
      samplesLength(0) {}

FieldBuilder::~FieldBuilder() 
{
    reset();
}

/* Public Functions */

void FieldBuilder::loadSampleFromFile(std::string fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
        throw std::runtime_error("Read FieldSample File");

    file >> samplesLength;
    samples = new FieldSample[samplesLength];
    for (size_t i = 0; i < samplesLength; i++) {
        file >> samples[i].width >> samples[i].height;
        samples[i].content = new unsigned short[samples[i].width * samples[i].height];
        for (size_t j = 0; j < samples[i].width * samples[i].height; j++) {
            file >> samples[i].content[j];
        }
    }
    file.close();
}

void FieldBuilder::build()
{
    if (!samples || samplesLength == 0)
        throw std::runtime_error("Field samples was not loaded");

    srand(time(NULL));
    size_t sampleNumber = rand() % samplesLength;

    size_t w = samples[sampleNumber].width;
    size_t h = samples[sampleNumber].height;

    target->setWidth(w);
    target->setHeight(h);
    target->tiles = new Tile *[w];
    for (size_t x = 0; x < w; x++) {
        target->tiles[x] = new Tile[h];
        for (size_t y = 0; y < h; y++) {
            target->tiles[x][y] = Tile(samples[sampleNumber].content[x + y * w]);
        }
    }
}

Field *FieldBuilder::getResult()
{
    Field *result = target;
    reset();
    return result;
}

/* Private Functions */

void FieldBuilder::reset()
{
    if (samples) {
        for (size_t i = 0; i < samplesLength; i++)
            delete[] samples[i].content;
        delete[] samples;
    }
    samples = nullptr;
    target = nullptr;
}