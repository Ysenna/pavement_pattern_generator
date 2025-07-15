#ifndef PATTERNGENERATOR_H
#define PATTERNGENERATOR_H

#include <random>
#include <vector>



struct Params
{
    unsigned areaWidth;
    unsigned areaHeight;
    unsigned rowHeight;
    unsigned seamThickness;
};



class PatternGeneratorTests;

class PatternGenerator {
public:
    std::vector<std::vector<unsigned>>  generate(
         unsigned areaWidth,
         unsigned areaHeight,
         unsigned seamThickness,
         unsigned rowHeight,
         std::vector<unsigned> tileWidths);

private:
    std::vector<std::vector<unsigned>> generateWithSeed(
        unsigned areaWidth,
        unsigned areaHeight,
        unsigned seamThickness,
        unsigned rowHeight,
        std::vector<unsigned> tileWidths,
        std::mt19937);

    friend class PatternGeneratorTests;
};



#endif //PATTERNGENERATOR_H
