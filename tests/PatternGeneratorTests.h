#ifndef PATTERNGENERATORTESTS_H
#define PATTERNGENERATORTESTS_H

#include <PatternGenerator.h>

class PatternGeneratorTests : public ::testing::Test {
protected:
    PatternGenerator patternGenerator;
    std::vector<unsigned> tileWidths = {40, 60, 90};
    const unsigned areaWidth = 200;
    const unsigned areaHeight = 100;
    const unsigned rowHeight = 20;
    const unsigned seamThickness = 2;

    const std::vector<std::vector<unsigned>> generateWithSeed(
        unsigned areaWidth,
        unsigned areaHeight,
        unsigned seamThickness,
        unsigned rowHeight,
        std::vector<unsigned> tileWidths,
        std::mt19937 mtGenerator);
};

#endif //PATTERNGENERATORTESTS_H
